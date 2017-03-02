#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Flacon(string nom, double volume, double pH);
  ostream& etiquete(ostream& sortie) const;
  const Flacon operator+(const Flacon& flacon) const;
  string getNom() const {return nom;}
  double getVolume() const {return volume;}
  double getPH() const {return pH;}

};

Flacon::Flacon(string nom, double volume, double pH)
  : nom(nom), volume(volume), pH(pH) {}

ostream& Flacon::etiquete(ostream& sortie) const {
  sortie << nom << " : " << volume << " ml, pH " << pH;
  return sortie;
}

ostream& operator<<(ostream& sortie, const Flacon& flacon) {
	return flacon.etiquete(sortie);
}

const Flacon Flacon::operator+(const Flacon& flacon) const {
	string melange_nom = nom + " + " + flacon.nom;
	double melange_volume = volume + flacon.volume;

	double melange_pH = - log10(((volume * pow(10, - pH)) + (flacon.volume * pow(10, - flacon.pH))) /
			                    (volume + flacon.volume));

	return Flacon(melange_nom, melange_volume, melange_pH);
}


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
