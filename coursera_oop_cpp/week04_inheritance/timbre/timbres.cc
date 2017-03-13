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

Timbre::Timbre(string nom, unsigned int anne, string pays, double valeur_faciale = 1.0) :
  nom(nom), anne(anne), pays(pays), 
  valeur_faciale(valeur_faciale) {}
  
double Timbre::vente() const {
  
}

unsigned int Timbre::age() const {

}

ostream& Timbre::afficher(ostream& out) const {

}

class Rare : public Timbre {
public:
  Rare(string nom, unsigned int anne, string pays,
       string valeur_faciale, unsigned int exemplaires = 100);
  double vente() const;
  ostream& afficher(ostream& out) const;
  unsigned int nb_exemplaires() const {return exemplaires;}

private:
  unsigned int exemplaires;
};

class Commemoratif : public Timbre {
public:
  Commemoratif(string nom, unsigned int anne, string pays, string valeur_faciale);
  double vente() const;
  ostream& afficher(ostream& out) const;
};

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
