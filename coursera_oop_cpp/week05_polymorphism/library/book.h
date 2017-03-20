/*
 * book.h
 *
 *  Created on: Mar 19, 2017
 *      Author: bknery
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>

class Book {
public:
  Book(std::string title, std::string author, unsigned int pages, bool bestSeller);
  virtual double calculatePrice() const;
  virtual void show() const;
  virtual ~Book();

protected:
  std::string title_;
  std::string author_;
  unsigned int pages_;
  bool bestSeller_;
};

#endif /* BOOK_H_ */
