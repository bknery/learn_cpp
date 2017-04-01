/*
 * mechanism.cc
 *
 *  Created on: Mar 30, 2017
 *      Author: bknery
 */

#include "mechanism.h"

Mechanism::Mechanism(double base_price, std::string time) :
  Product(base_price), time_(time) {}

void Mechanism::show(std::ostream& out) const {
  out << "Mechanism: ";
  showType(out);
  out << std::endl;
  out << "  display: ";
  showDisplay(out);
  out << std::endl;
  out << "  price: ";
  Product::show(out);
}

void Mechanism::showDisplay(std::ostream& out) const {
  out << "time " << time_;
}
