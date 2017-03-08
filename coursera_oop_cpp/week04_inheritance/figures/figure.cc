/*
 * figure.cc
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#include <iostream>
#include <string>
#include "figure.h"

Figure::Figure(double x, double y) : x_(x), y_(y) {}

double Figure::getX() const {
  return x_;
}

double Figure::getY() const {
  return y_;
}

void Figure::setX(double x) {
  x_ = x;
}

void Figure::setY(double y) {
  y_ = y;
}

void Figure::drawCenter() const {
  std::cout << "center: (" << x_ << ", " << y_ << ")" << std::endl;
}
