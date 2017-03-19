/*
 * square.cc
 *
 *  Created on: Mar 19, 2017
 *      Author: bknery
 */

#include <iostream>
#include "square.h"

Square::Square(double side) : side_(side) {
  std::cout << "Creating a square, side: " << side << std::endl;
}

Square::Square(const Square& s) : side_(s.side_) {
  std::cout << "Copy creating a square, side: " << s.side_ << std::endl;
}

void Square::show() const {
  std::cout << "Square, side: " << side_ << std::endl;
}

Figure* Square::copy() const {
  return new Square(*this);
}

Square::~Square() {
  std::cout << "Destructing square, side: " << side_ << std::endl;
}
