/*
 * illustrated_book.h
 *
 *  Created on: 20 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef ILLUSTRATED_BOOK_H_
#define ILLUSTRATED_BOOK_H_

#include "book.h"
#include <iostream>

class IllustratedBook : public Book {
public:
  IllustratedBook(std::string title, std::string author, unsigned int pages, bool bestSeller);
  virtual double calculatePrice() const override;
  virtual void show(std::ostream& out) const override;
  virtual ~IllustratedBook();
};

#endif /* ILLUSTRATED_BOOK_H_ */
