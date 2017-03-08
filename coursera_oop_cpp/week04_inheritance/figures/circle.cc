/*
 * circle.cc
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#include "circle.h"
#include <cmath>
#include <iostream>

Circle::Circle(double x, double y, double r) : Figure(x, y), r_(r) {}

double Circle::area() const {
  return M_PI * r_ * r_;
}

double Circle::getR() const {
  return r_;
}

void Circle::setR(double r) {
  if (r < 0) {
    r_ = 0;
  } else {
    r_ = r;
  }
}

void Circle::draw() const {
  std::cout << "Circle: " << std::endl;
  std::cout << "  "; drawCenter();
  std::cout << "  radius: " << r_ << ", area: " << area() << std::endl;
}
