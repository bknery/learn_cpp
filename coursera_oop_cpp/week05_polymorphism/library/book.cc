/*
 * book.cc
 *
 *  Created on: 20 de mar de 2017
 *      Author: bruno.nery
 */

#include <string>
#include "book.h"

Book::Book(std::string title, std::string author, unsigned int pages, bool bestSeller) :
  title_(title), author_(author), pages_(pages), bestSeller_(bestSeller) {
  std::cout << "Creating book..." << std::endl;
}

double Book::calculatePrice() const {
  double price(pages_ * 0.3);

  if (bestSeller_) {
    price += 50;
  }

  return price;
}

void Book::show(std::ostream& out) const {
  out << "Title: " << title_ << std::endl
      << "Author: " << author_ << std::endl
      << "Number of pages: " << pages_ << std::endl
      << "Bestseller: ";

  if (bestSeller_) {
    out << "yes";
  } else {
    out << "no";
  }
  out << std::endl;
}

Book::~Book() {
  std::cout << "Destructing book..." << std::endl;
}
