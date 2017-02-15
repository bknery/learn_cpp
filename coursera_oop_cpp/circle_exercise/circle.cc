/*
 * circle.cc
 *
 *  Created on: 15 de fev de 2017
 *      Author: bruno.nery
 */

#include "circle.h"
#include <cmath>

Circle::Circle(void) {
  x_ = 0;
  y_ = 0;
  r_ = 1;
}

Circle::Circle(double x, double y, double r) {
  x_ = x;
  y_ = y;
  r_ = r;
}

void Circle::setCenter(double x, double y) {
  x_ = x;
  y_ = y;
}

void Circle::setR(double r) { r_ = r; }

void Circle::getCenter(double& x, double& y) const {
  x = x_;
  y = y_;
}

void Circle::getR(double& r) const { r = r_; }

double Circle::area(void) const { return M_PI * r_ * r_; }

bool Circle::isIn(double x, double y) const {
  if (((x - x_) * (x - x_) + (y - y_) * (y - y_)) < (r_ * r_)) {
    return true;
  } else {
    return false;
  }
}

Circle::~Circle(void) {}
