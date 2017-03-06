#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire {
public:
	double getMontant() const;
	void afficher() const;
	void secouer() const;
	void remplir(double argent);
	void vider();
	void puiser(double argent);
	bool montant_suffisant(double budget, double& solde) const;
	double calculerSolde(double budget) const;
private:
	double montant;
};

double Tirelire::getMontant() const {
	return montant;
}

void Tirelire::afficher() const {
	if (montant == 0) {
		cout << "Vous etes sans le sou." << endl;
	} else {
		cout << "Vous avez : " << montant << " euros dans votre tirelire." << endl;
	}
}

void Tirelire::secouer() const {
	if (montant > 0) {
		cout << "Bing bing" << endl;
	}
}

void Tirelire::remplir(double argent) {
	if (argent > 0) {
		montant = montant + argent;
	}
}

void Tirelire::vider() {
	montant = 0;
}

void Tirelire::puiser(double argent) {
	if (argent > 0) {
		if (argent >= montant) {
			montant = 0;
		} else {
			montant = montant - argent;
		}
	}
}

bool Tirelire::montant_suffisant(double budget, double& solde) const {
	if (budget <= 0) {
		solde = montant;
		return true;
	} else {
		if (montant >= budget) {
			solde = montant - budget;
			return true;
		} else {
			solde = budget - montant;
			return false;
		}
	}
}

double Tirelire::calculerSolde(double budget) const {
	if (budget <= 0) {
		return montant;
	} else {
		return montant - budget;
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
