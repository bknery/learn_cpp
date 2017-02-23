#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient {
public:
	void init(double poids, double taille);
	void afficher() const;
	double imc() const;
	double taille() const;
	double poids() const;
private:
	double masse;
	double hauteur;
};

void Patient::init(double poids, double taille){
	if ((poids > 0) && (taille > 0)){
		masse = poids;
		hauteur = taille;
	} else {
		masse = 0;
		hauteur = 0;
	}
}

void Patient::afficher() const {
	cout << "Patient : " << masse << " kg pour " << hauteur << " m" << endl;
}

double Patient::poids() const {
	return masse;
}

double Patient::taille() const {
	return hauteur;
}

double Patient::imc() const {
	if (hauteur == 0){
		return 0;
	} else {
		return masse / (hauteur * hauteur);
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
