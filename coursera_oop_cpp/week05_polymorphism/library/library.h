/*
 * library.h
 *
 *  Created on: 21 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>
#include <vector>
#include <memory>
#include "book.h"

class Library {
public:
  void addBook(Book* book);
  void show(std::ostream& out) const;
  void deleteBooks();
  ~Library();

private:
  std::vector<std::unique_ptr<Book>> books_;
};

#endif /* LIBRARY_H_ */
