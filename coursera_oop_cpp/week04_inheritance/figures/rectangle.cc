/*
 * rectangle.cc
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#include "rectangle.h"

Rectangle::Rectangle(double x, double y, double width, double height)
  : Figure(x, y), width_(width), height_(height) {}

double Rectangle::area() const {
  return width_ * height_;
}

double Rectangle::getWidth() const {
  return width_;
}

double Rectangle::getHeight() const {
  return height_;
}

void Rectangle::setWidth(double width) {
  if (width < 0) {
    width_ = 0;
  } else {
    width_ = width;
  }
}

void Rectangle::setHeight(double height) {
  if (height < 0) {
    height_ = 0;
  } else {
    height_ = height;
  }
}
