/*
 * product.cc
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#include <iostream>
#include "product.h"

Product::Product(double value) : value_(value) {}

double Product::price() const {
  return value_;
}

void Product::show(std::ostream& out) const {
  out << price();
}

Product::~Product() {}

std::ostream& operator<<(std::ostream& out, const Product& product) {
  product.show(out);
  return out;
}
