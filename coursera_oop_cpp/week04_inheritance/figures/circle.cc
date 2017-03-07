/*
 * circle.cc
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#include "circle.h"
#include <cmath>

Circle::Circle(double r) : r_(r) {}

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
