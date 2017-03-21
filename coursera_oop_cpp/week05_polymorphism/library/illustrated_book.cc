/*
 * illustrated_book.cc
 *
 *  Created on: 21 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "illustrated_book.h"

IllustratedBook::IllustratedBook(std::string title, std::string author, unsigned int pages, bool bestSeller) :
  Book(title, author, pages, bestSeller) {
  std::cout << "Creating illustrated book..." << std::endl;
}

double IllustratedBook::calculatePrice() const {
  return 30 + Book::calculatePrice();
}

void IllustratedBook::show(std::ostream& out) const {
  Book::show(out);
  out << "Type: Illustrated book" << std::endl;
}

IllustratedBook::~IllustratedBook() {
  std::cout << "Destructing illustrated book..." << std::endl;
}
