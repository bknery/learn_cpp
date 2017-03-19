/*
 * triangle.cc
 *
 *  Created on: Mar 19, 2017
 *      Author: bknery
 */

#include <iostream>
#include "triangle.h"

Triangle::Triangle(double base, double height) : base_(base), height_(height) {
  std::cout << "Creating a triangle, base: " << base << ", height: " << height << std::endl;
}

Triangle::Triangle(const Triangle& t) : base_(t.base_), height_(t.height_) {
  std::cout << "Copy creating a triangle, base: " << t.base_
      << ", height: " << t.height_ << std::endl;
}

void Triangle::show() const {
  std::cout << "Triangle, base: " << base_ << ", height: " << height_ << std::endl;
}

Figure* Triangle::copy() const {
  return new Triangle(*this);
}

Triangle::~Triangle() {
  std::cout << "Destructing triangle, base: " << base_ << ", height: " << height_ << std::endl;
}
