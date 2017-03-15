#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
public:
  Timbre(string nom, unsigned int anne, string pays = "Suisse", double valeur_faciale = 1.0);
  double vente() const;
  unsigned int age() const;
  ostream& afficher(ostream& out) const;

protected:
  string nom;
  unsigned int anne;
  string pays;
  double valeur_faciale;
};

Timbre::Timbre(string nom, unsigned int anne, string pays, double valeur_faciale) :
  nom(nom), anne(anne), pays(pays), 
  valeur_faciale(valeur_faciale) {}
  
double Timbre::vente() const {
  if (age() < 5) {
    return valeur_faciale;
  } else {
    return valeur_faciale * (2.5 * age());
  }
}

unsigned int Timbre::age() const {
  return ANNEE_COURANTE - anne;
}

ostream& Timbre::afficher(ostream& out) const {
  out << "de nom " << nom << " datant de " << anne << " (provenance " << pays
      << ") ayant pour valeur faciale " << valeur_faciale << " francs";
  return out;
}

ostream& operator<<(ostream& out, const Timbre& timbre) {
  out << "Timbre ";
  return timbre.afficher(out);
}

class Rare : public Timbre {
public:
  Rare(string nom, unsigned int anne, string pays,
       double valeur_faciale, unsigned int exemplaires = 100);
  double vente() const;
  ostream& afficher(ostream& out) const;
  unsigned int nb_exemplaires() const {return exemplaires;}

private:
  unsigned int exemplaires;
  static constexpr unsigned int PRIX_BASE_TRES_RARE = 600;
  static constexpr unsigned int PRIX_BASE_RARE = 400;
  static constexpr unsigned int PRIX_BASE_PEU_RARE = 50;
};

Rare::Rare(string nom, unsigned int anne, string pays,
           double valeur_faciale, unsigned int exemplaires) :
               Timbre(nom, anne, pays, valeur_faciale),
               exemplaires(exemplaires) {}

double Rare::vente() const {
  unsigned int prix_base = 0;
  if (exemplaires < 100) {
    prix_base = PRIX_BASE_TRES_RARE;
  } else if ((exemplaires >= 100) && (exemplaires < 1000)) {
    prix_base = PRIX_BASE_RARE;
  } else {
    prix_base = PRIX_BASE_PEU_RARE;
  }
  return prix_base * (age() / 10.0);
}

ostream& Rare::afficher(ostream& out) const {
  out << "Timbre rare (" << exemplaires << " ex.) ";
  return Timbre::afficher(out);
}

ostream& operator<<(ostream& out, const Rare& timbre) {
  return timbre.afficher(out);
}

class Commemoratif : public Timbre {
public:
  Commemoratif(string nom, unsigned int anne, string pays, double valeur_faciale);
  double vente() const;
  ostream& afficher(ostream& out) const;
};

Commemoratif::Commemoratif(string nom, unsigned int anne, string pays, double valeur_faciale) :
    Timbre(nom, anne, pays, valeur_faciale) {}

double Commemoratif::vente() const {
  return 2 * Timbre::vente();
}

ostream& Commemoratif::afficher(ostream& out) const {
  out << "Timbre commémoratif ";
  return Timbre::afficher(out);
}

ostream& operator<<(ostream& out, const Commemoratif& timbre) {
  return timbre.afficher(out);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
