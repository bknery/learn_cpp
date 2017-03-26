#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/

class Produit {
public:
  Produit(string nom, string unite = "") :
    nom_(nom), unite_(unite) {}
  virtual string getNom() const {return nom_;}
  virtual string getUnite() const {return unite_;}
  virtual string toString() const {return nom_;}
  virtual const Produit* adapter(double n) const;
  virtual double quantiteTotale(const string& nomProduit) const;
  virtual ~Produit() {}

protected:
  string nom_;
  string unite_;
};

const Produit* Produit::adapter(double n) const {
  return new Produit(*this);
}

double Produit::quantiteTotale(const string& nomProduit) const {
  if (nom_ == nomProduit) {
    return 1;
  } else {
    return 0;
  }
}

class Ingredient {
public:
  Ingredient(const Produit& produit, double quantite) :
    produit_(produit), quantite_(quantite) {}
  const Produit& getProduit() const {return produit_;}
  double getQuantite() const {return quantite_;}
  void setQuantite(double quantite) {quantite_ = quantite;}
  double quantiteTotale(const string& nomProduit) const;
  string descriptionAdaptee() const;

protected:
  const Produit& produit_;
  double quantite_;
};

string Ingredient::descriptionAdaptee() const {

  const Produit* pproduit(produit_.adapter(quantite_));

  ostringstream strs;
  strs << to_string(quantite_) << " " << pproduit->getUnite() << " de " << pproduit->toString();
  delete pproduit;
  return strs.str();
}

double Ingredient::quantiteTotale(const string& nomProduit) const {
  return quantite_ * produit_.quantiteTotale(nomProduit);
}

class Recette {
public:
  Recette(string nom, double nbFois = 1.0) :
    nom_(nom), nbFois_(nbFois) {}
  void ajouter(const Produit& p, double quantite);
  Recette adapter(double n) const;
  string toString() const;
  double quantiteTotale(const string& nomProduit) const;
  ~Recette();

protected:
  string nom_;
  double nbFois_;
  vector<Ingredient*> ingredients_;
};

void Recette::ajouter(const Produit& p, double quantite) {
  ingredients_.push_back(new Ingredient(p, nbFois_ * quantite));
}

Recette Recette::adapter(double n) const {
  Recette recette(*this);
  for (auto ingredient : recette.ingredients_) {
    double quantite(ingredient->getQuantite());
    ingredient->setQuantite(quantite * n);
  }
  recette.nbFois_ = n * nbFois_;
  return recette;
}

string Recette::toString() const {
  ostringstream strs;
  strs << "Recette \"" << nom_ << "\" x " << nbFois_ << endl;

  int i = 1;
  for (vector<Ingredient*>::const_iterator it = ingredients_.begin(); it != ingredients_.end(); ++it) {
    strs << i << ". " << (*it)->descriptionAdaptee();
    if (it != (ingredients_.end() - 1)) {
      strs << endl;
    }
    ++i;
  }

  return strs.str();
}

double Recette::quantiteTotale(const string& nomProduit) const {
  double quantite(0);
  for (auto ingredient : ingredients_) {
    if (ingredient->getProduit().getNom() == nomProduit) {
      quantite += ingredient->getQuantite();
    }
  }
  return quantite;
}

Recette::~Recette() {}

class ProduitCuisine : public Produit {
public:
  ProduitCuisine(string nom) : Produit(nom, "portion(s)"), recette_(nom) {}
  virtual void ajouterARecette(const Produit& produit, double quantite);
  virtual const ProduitCuisine* adapter(double n) const override;
  virtual string toString() const override;
  virtual double quantiteTotale(const string& nomProduit) const override;
  virtual ~ProduitCuisine() {}
private:
  Recette recette_;
};

void ProduitCuisine::ajouterARecette(const Produit& produit, double quantite) {
  recette_.ajouter(produit, quantite);
}

const ProduitCuisine* ProduitCuisine::adapter(double n) const {
  ProduitCuisine* pproduit(new ProduitCuisine(*this));
  pproduit->recette_.adapter(n);

  return pproduit;
}

string ProduitCuisine::toString() const {
  ostringstream strs;
  strs << Produit::toString() << endl;
  strs << recette_.toString();
  return strs.str();
}

double ProduitCuisine::quantiteTotale(const string& nomProduit) const {
  if (nom_ == nomProduit) {
    return 1;
  } else {
    return recette_.quantiteTotale(nomProduit);
  }
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
