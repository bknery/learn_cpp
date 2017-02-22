/*
 * point_3D.cc
 *
 *  Created on: Feb 21, 2017
 *      Author: bknery
 */

#include "point_3D.h"
#include <cmath>
#include <iostream>

Point3D::Point3D() {
  x_ = 0;
  y_ = 0;
  z_ = 0;
}

Point3D::Point3D(float x, float y, float z) {
  x_ = x;
  y_ = y;
  z_ = z;
}

void Point3D::show() const {
  std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";
}

bool Point3D::compare(const Point3D& point) const {
  if ((x_ == point.getX()) && (y_ == point.getY()) && (z_ == point.getZ())) {
    return true;
  } else {
    return false;
  }
}

void Point3D::setX(float x) { x_ = x; }

double Point3D::distance(const Point3D& point) const {
  float x2 = point.getX();
  float y2 = point.getY();
  float z2 = point.getZ();

  return sqrt((x_ - x2) * (x_ - x2) + (y_ - y2) * (y_ - y2) +
              (z_ - z2) * (z_ - z2));
}
