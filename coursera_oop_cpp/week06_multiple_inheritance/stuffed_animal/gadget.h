/*
 * gadget.h
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef GADGET_H_
#define GADGET_H_

#include <string>

class Gadget {
public:
  Gadget(std::string name, double price);
  void show() const;
  void showPrice() const;
  ~Gadget();

protected:
  std::string name_;
  double price_;

};

#endif /* GADGET_H_ */
