/*
 * figure.cc
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#include "figure.h"
#include <string>

Figure::Figure() : color_("white") {}

Figure::Figure(std::string color) : color_(color) {}

std::string Figure::getColor() const {
  return color_;
}

void Figure::setColor(std::string color) {
  color_ = color;
}

