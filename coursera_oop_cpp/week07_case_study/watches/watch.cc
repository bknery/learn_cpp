/*
 * watch.cc
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#include <iostream>
#include "watch.h"

Watch::Watch(double base_price) : Product(base_price) {}

double Watch::price() const {
  double final_price(Product::price());
  for (auto const& p_accessory : accessories_) {
    final_price += p_accessory->price();
  }
  return final_price;
}

void Watch::show(std::ostream& out) const {
  out << "A watch composed of:" << std::endl;
  for (auto const& p_accessory : accessories_) {
    out << "  - " << *p_accessory << std::endl;
  }
  out << "  ==> Total price: " << price() << std::endl;
}

void Watch::add(Accessory* p_accessory) {
  accessories_.push_back(std::unique_ptr<Accessory>(p_accessory));
}

Watch::~Watch() {
  accessories_.clear();
}
