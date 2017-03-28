#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
public:
  Navire(int x, int y, Pavillon pavillon) : position_(x, y), pavillon_(pavillon), etat_(Intact) {}
  const Coordonnees& position() const;
  void avancer(int de_x, int de_y);
  void renflouer();
  virtual ostream& afficher(ostream& out) const;
  virtual void attaque(Navire& autre) = 0;
  virtual void replique(Navire& autre) = 0;
  virtual void est_touche() = 0;
  virtual void rencontrer(Navire& autre);
  virtual ~Navire() {}

protected:
  Coordonnees position_;
  Pavillon pavillon_;
  Etat etat_;
  static constexpr unsigned int rayon_rencontre = 10;
};

double distance(const Coordonnees& c1, const Coordonnees& c2) {
  return sqrt(sq(c1.x() - c2.x()) + sq(c1.y() - c2.y()));
}

double distance(const Navire& n1, const Navire& n2) {
  return distance(n1.position(), n2.position());
}

ostream& operator<<(ostream& out, const Coordonnees& c) {
  out << "(" << c.x() << ", " << c.y() << ")";
  return out;
}

ostream& operator<<(ostream& out, const Pavillon& p) {
  switch (p) {
    case JollyRogers:
      out << "pirate";
      break;
    case CompagnieDuSenegal:
      out << "français";
      break;
    case CompagnieDOstende:
      out << "autrichien";
      break;
    default:
      out << "pavillon inconnu";
  }
  return out;
}

ostream& operator<<(ostream& out, const Etat& e) {
  switch (e) {
    case Intact:
      out << "intact";
      break;
    case Endommage:
      out << "ayant subi des dommages";
      break;
    case Coule:
      out << "coulé";
      break;
    default:
      out << "état inconnu";
  }
  return out;
}

const Coordonnees& Navire::position() const {
  return position_;
}

void Navire::avancer(int de_x, int de_y) {

  if (etat_ != Coule) {
    Coordonnees c(de_x, de_y);
    position_ += c;
  }
}

void Navire::renflouer() {
  etat_ = Intact;
}

ostream& Navire::afficher(ostream& out) const {
  out << " en " << position_ << " battant pavillon " << pavillon_ << ", " << etat_;
  return out;
}

void Navire::rencontrer(Navire& autre) {
  if ((etat_ != Coule) && (autre.etat_ != Coule) &&
      (pavillon_ != autre.pavillon_) && (distance(*this, autre) < rayon_rencontre)) {
    attaque(autre);
    autre.replique(*this);
  }
}

ostream& operator<<(ostream& out, const Navire& navire) {
  return navire.afficher(out);
}

void Coordonnees::operator+=(Coordonnees const& autre)
{
  x_ += autre.x_;
  y_ += autre.y_;
}

class Pirate : public virtual Navire {
public:
  Pirate(int x, int y, Pavillon pavillon) : Navire(x, y, pavillon) {}
  virtual ostream& afficher(ostream& out) const override;
  virtual void attaque(Navire& autre) override;
  virtual void replique(Navire& autre) override;
  virtual void est_touche() override;
  virtual ~Pirate() {}
};

ostream& Pirate::afficher(ostream& out) const {
  out << "bateau pirate";
  return Navire::afficher(out);
}

void Pirate::attaque(Navire& autre) {
  if (etat_ != Coule) {
    cout << "A l'abordage !" << endl;
    autre.est_touche();
  }
}

void Pirate::replique(Navire& autre) {
  if (etat_ != Coule) {
    cout << "Non mais, ils nous attaquent ! On riposte !!" << endl;
    attaque(autre);
  }
}

void Pirate::est_touche() {
  switch (etat_) {
    case Intact:
      etat_ = Endommage;
      break;
    case Endommage:
      etat_ = Coule;
      break;
    default:
      break;
  }
}

class Marchand : public virtual Navire {
public:
  Marchand(int x, int y, Pavillon pavillon) : Navire(x, y, pavillon) {}
  virtual ostream& afficher(ostream& out) const override;
  virtual void attaque(Navire& autre) override;
  virtual void replique(Navire& autre) override;
  virtual void est_touche() override;
  virtual ~Marchand() {}
};

ostream& Marchand::afficher(ostream& out) const {
  out << "navire marchand";
  return Navire::afficher(out);
}

void Marchand::attaque(Navire& autre) {
  if (etat_ != Coule) {
    cout << "On vous aura ! (insultes) " << endl;
  }
}

void Marchand::replique(Navire& autre) {
  if (etat_ == Coule) {
    cout << "SOS je coule !" << endl;
  } else {
    cout << "Même pas peur !" << endl;
  }
}

void Marchand::est_touche() {
  etat_ = Coule;
}

class Felon : public Pirate, public Marchand {
public:
  Felon(int x, int y, Pavillon pavillon) :
    Navire(x, y, pavillon),
    Pirate(x, y, pavillon),
    Marchand(x, y, pavillon) {}
  virtual ostream& afficher(ostream& out) const override;
  virtual void attaque(Navire& autre) override;
  virtual void replique(Navire& autre) override;
  virtual void est_touche() override;
  virtual ~Felon() {}
};

ostream& Felon::afficher(ostream& out) const {
  out << "navire félon";
  return Navire::afficher(out);
}

void Felon::attaque(Navire& autre) {
  Pirate::attaque(autre);
}

void Felon::replique(Navire& autre) {
  Marchand::replique(autre);
}

void Felon::est_touche() {
  Pirate::est_touche();
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);

  return 0;
}
