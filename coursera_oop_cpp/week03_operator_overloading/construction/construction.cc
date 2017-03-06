#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Brique() : forme("pleine"), couleur("blanc") {}
  Brique(Forme forme, Couleur couleur) : forme(forme), couleur(couleur) {}
  ostream& afficher(ostream& sortie) const;

};

ostream& Brique::afficher(ostream& sortie) const {
  if (couleur.empty()){
    sortie << forme;
  } else {
    sortie << "(" << forme << ", " << couleur << ")";
  }
  return sortie;
}

ostream& operator<<(ostream& sortie, const Brique& brique) {
  return brique.afficher(sortie);
}

class Construction
{
  friend class Grader;

public:
  Construction(Brique brique);
  ostream& afficher(ostream& sortie) const;
  void operator^=(const Construction& b);
  void operator-=(const Construction& b);
  void operator+=(const Construction& b);
  int getHeight() const {return contenu.size();}
  int getDeep() const {return contenu[0].size();}
  int getWidth() const {return contenu[0][0].size();}
private:
  vector<vector<vector<Brique>>> contenu;
};

Construction::Construction(Brique brique)
  : contenu(1, vector<vector<Brique>>(1, vector<Brique>(1))) {
  contenu[0][0][0] = brique;
}

ostream& Construction::afficher(ostream& sortie) const {
  if (!contenu.empty()) {
    int height(getHeight());

    int x(height -1);
    for (vector<vector<vector<Brique>>>::const_reverse_iterator i = contenu.rbegin(); i != contenu.rend(); ++i) {
      sortie << "Couche " << x << " :" << endl;
      for (vector<vector<Brique>>::const_iterator j = i->begin(); j != i->end(); ++j) {
        for (vector<Brique>::const_iterator k = j->begin(); k != j->end(); ++k) {
          sortie << *k << " ";
        }
        sortie << endl;
      }
      --x;
    }
  }
  return sortie;
}

ostream& operator<<(ostream& sortie, const Construction& construction) {
  return construction.afficher(sortie);
}

void Construction::operator^=(const Construction& b) {
  contenu.insert(contenu.end(), b.contenu.begin(), b.contenu.end());
}

void Construction::operator-=(const Construction& b) {
  if(!(b.getHeight() < getHeight())) {
    for (int i = 0; i < getHeight(); ++i) {
      contenu[i].insert(contenu[i].end(), b.contenu[i].begin(), b.contenu[i].end());
    }
  }
}

void Construction::operator+=(const Construction& b) {
  if(!(b.getHeight() < getHeight())) {
    if (!(b.getDeep() < getDeep())) {
      for (int i = 0; i < getHeight(); ++i) {
        for (int j = 0; j < getDeep(); ++j) {
          contenu[i][j].insert(contenu[i][j].end(), b.contenu[i][j].begin(), b.contenu[i][j].end());
        }
      }
    }
  }
}

const Construction operator^(Construction a, const Construction& b) {
  a ^= b;
  return a;
}

const Construction operator-(Construction a, const Construction& b) {
  a -= b;
  return a;
}

const Construction operator+(Construction a, const Construction& b) {
  a += b;
  return a;
}

const Construction operator*(unsigned int n, Construction const& a)
{
  Construction b(a);
  for (unsigned int i = 1; i < n; ++i){
    b += a;
  }
  return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{
  Construction b(a);
  for (unsigned int i = 1; i < n; ++i){
    b ^= a;
  }
  return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{
  Construction b(a);
  for (unsigned int i = 1; i < n; ++i){
    b -= a;
  }
  return b;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
