/*
 * police_romance.cc
 *
 *  Created on: 21 de mar de 2017
 *      Author: bruno.nery
 */

#include "police_romance.h"

PoliceRomance::PoliceRomance(std::string title, std::string author, unsigned int pages, bool bestSeller) :
  Romance(title, author, pages, bestSeller, false) {
  std::cout << "Creating police romance..." << std::endl;
}

double PoliceRomance::calculatePrice() const {
  double price(Book::calculatePrice() - 10);

  if (price < 0) {
    return 1;
  } else {
    return price;
  }
}

void PoliceRomance::show(std::ostream& out) const {
  Book::show(out);
  out << "Type: Police Romance" << std::endl;
}

PoliceRomance::~PoliceRomance() {
  std::cout << "Destructing police romance..." << std::endl;
}
