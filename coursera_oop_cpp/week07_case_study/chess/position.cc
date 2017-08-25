/*
 * position.cc
 *
 *  Created on: Apr 21, 2017
 *      Author: bknery
 */

#include "position.h"

Position::Position(int x, int y) : x_(x), y_(y) {
  // limit x from 1 to 8
  if (x_ < 1) {
    x_ = 1;
  } else if (x_ > 8) {
    x_ = 8;
  }
  // limit y from 1 to 8
  if (y_ < 1) {
    y_ = 1;
  } else if (y_ > 8) {
    y_ = 8;
  }
}

void Position::setX(int x) {
  if (x < 1) {
    x_ = 1;
  } else if (x > 8) {
    x_ = 8;
  } else {
    x_ = x;
  }
}

void Position::setY(int y) {
  if (y < 1) {
    y_ = 1;
  } else if (y > 8) {
    y_ = 8;
  } else {
    y_ = y;
  }
}

void Position::show(std::ostream& out) const {
  out << "(" << x_ << ", " << y_ << ")";
}
