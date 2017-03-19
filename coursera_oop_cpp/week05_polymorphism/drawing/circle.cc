/*
 * circle.cc
 *
 *  Created on: Mar 18, 2017
 *      Author: bknery
 */

#include <iostream>
#include "circle.h"

Circle::Circle(double r) : r_(r) {
  std::cout << "Creating a circle r: " << r << std::endl;
}

Circle::Circle(const Circle& c) : r_(c.r_) {
  std::cout << "Copy creating a circle r: " << c.r_ << std::endl;
}

void Circle::show() const {
  std::cout << "Circle r: " << r_ << std::endl;
}

Figure* Circle::copy() const {
  return new Circle(*this);
}

Circle::~Circle() {
  std::cout << "Destructing circle r: " << r_ << std::endl;
}

