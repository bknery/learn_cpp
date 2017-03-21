/*
 * library.cc
 *
 *  Created on: 21 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "library.h"

void Library::addBook(Book* book) {
  if (book != nullptr) {
    books_.push_back(std::unique_ptr<Book>(book));
  }
}

void Library::show(std::ostream& out) const {
  for (auto const& book : books_) {
    book->show(out);
    out << "Price: " << book->calculatePrice() << std::endl;
    out << std::endl;
  }
}

void Library::deleteBooks() {
  std::cout << "Clearing library..." << std::endl;
  books_.clear();
}

Library::~Library() {
  std::cout << "Destructing library..." << std::endl;
  books_.clear();
}
