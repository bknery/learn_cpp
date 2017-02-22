/*
 * triangle.cc
 *
 *  Created on: Feb 21, 2017
 *      Author: bknery
 */

#include "triangle.h"
#include <cmath>

Triangle::Triangle(Point3D p1, Point3D p2, Point3D p3) {
	p1_ = p1;
	p2_ = p2;
	p3_ = p3;
}

double Triangle::perimeter() const {
  return p1_.distance(p2_) + p2_.distance(p3_) + p3_.distance(p1_);
}

bool Triangle::isIsosceles() const {
  double side1 = p1_.distance(p2_);
  double side2 = p2_.distance(p3_);
  double side3 = p3_.distance(p1_);

  if ((side1 == side2) || (side1 == side3) || (side2 == side3)) {
	  return true;
  } else {
	  return false;
  }
}


