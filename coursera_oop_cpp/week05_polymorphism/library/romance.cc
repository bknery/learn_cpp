/*
 * romance.cc
 *
 *  Created on: 20 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "romance.h"

Romance::Romance(std::string title, std::string author, unsigned int pages, bool bestSeller, bool biography) :
  Book(title, author, pages, bestSeller), biography_(biography) {
  std::cout << "Creating romance..." << std::endl;
}

void Romance::show(std::ostream& out) const {
  Book::show(out);
  out << "Biography: ";
  if (biography_) {
    out << "yes";
  } else {
    out << "no";
  }
  out << std::endl;
  out << "Type: Romance" << std::endl;
}

Romance::~Romance() {
  std::cout << "Destructing romance..." << std::endl;
}
