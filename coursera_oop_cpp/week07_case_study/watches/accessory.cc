/*
 * accessory.cc
 *
 *  Created on: Mar 29, 2017
 *      Author: bknery
 */

#include <iostream>
#include "accessory.h"

Accessory::Accessory(const std::string& name, double base_price) :
  Product(base_price), name_(name) {}

void Accessory::show(std::ostream& out) const {
  out << name_ << " costing: ";
  Product::show(out);
}
