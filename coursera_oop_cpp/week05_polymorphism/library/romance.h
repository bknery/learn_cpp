/*
 * romance.h
 *
 *  Created on: 20 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef ROMANCE_H_
#define ROMANCE_H_

#include <iostream>
#include "book.h"

class Romance : public Book {
public:
  Romance(std::string title, std::string author, unsigned int pages, bool bestSeller, bool biography);
  virtual void show(std::ostream& out) const override;
  virtual ~Romance();

protected:
  bool biography_;
};

#endif /* ROMANCE_H_ */
