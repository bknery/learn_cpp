#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

class Auteur {
public:
	Auteur(string nom, bool prime = false)
		: nom_(nom), prime_(prime) {}
	Auteur(Auteur const&) = delete;
	string getNom() const {return nom_;}
	bool getPrix() const {return prime_;}
private:
	string nom_;
	bool prime_;
};

class Oeuvre {
public:
	Oeuvre(string titre, const Auteur& auteur, string langue)
		: titre_(titre), auteur_(auteur), langue_(langue) {}
	string getTitre() const {return titre_;}
	Oeuvre(Oeuvre const&) = delete;
	const Auteur& getAuteur() const {return auteur_;}
	string getLangue() const {return langue_;}
	void affiche() const;
	~Oeuvre();
private:
	string titre_;
	const Auteur& auteur_;
	string langue_;
};

void Oeuvre::affiche() const {
	cout << titre_ << ", " << auteur_.getNom() << ", en " << langue_ << endl;
}

Oeuvre::~Oeuvre() {
	cout << "L'oeuvre \"" << titre_ << ", " << auteur_.getNom() << ", en "
			<< langue_ << "\" n'est plus disponible." << endl;
}

class Exemplaire {
public:
	Exemplaire(const Oeuvre& oeuvre);
	Exemplaire(const Exemplaire& exemplaire);
	~Exemplaire();
	const Oeuvre& getOeuvre() const {return oeuvre_;}
	void affiche() const;
private:
	const Oeuvre& oeuvre_;
};

Exemplaire::Exemplaire(const Oeuvre& oeuvre) : oeuvre_(oeuvre) {
	cout << "Nouvel exemplaire de : "
			<< oeuvre_.getTitre()
			<< ", "
			<< oeuvre_.getAuteur().getNom() << ", en "
			<< oeuvre_.getLangue()
			<< endl;
}

Exemplaire::Exemplaire(const Exemplaire& exemplaire) : oeuvre_(exemplaire.oeuvre_) {
	cout << "Copie d'un exemplaire de : "
			<< oeuvre_.getTitre()
			<< ", "
			<< oeuvre_.getAuteur().getNom() << ", en "
			<< oeuvre_.getLangue()
			<< endl;
}

Exemplaire::~Exemplaire() {
	cout << "Un exemplaire de : "
			<< oeuvre_.getTitre()
			<< ", "
			<< oeuvre_.getAuteur().getNom() << ", en "
			<< oeuvre_.getLangue() << ", a été jeté !"
			<< endl;
}

void Exemplaire::affiche() const {
	cout << "Exemplaire de : "
		<< oeuvre_.getTitre()
		<< ", "
		<< oeuvre_.getAuteur().getNom() << ", en "
		<< oeuvre_.getLangue()
		<< endl;
}

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
