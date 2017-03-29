/*
 * product.cc
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#include <iostream>
#include "product.h"

Product::Product(const std::string& name, double value) :
  name_(name), value_(value) {
  std::cout << "new product" << std::endl;
}

double Product::price() const {
  return value_;
}

void Product::show(std::ostream& out) const {
  out << price() << std::endl;
}

Product::~Product() {}

std::ostream& operator<<(std::ostream& out, const Product& product) {
  product.show(out);
  return out;
}
