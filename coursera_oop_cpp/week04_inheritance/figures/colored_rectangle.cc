/*
 * colored_rectangle.cc
 *
 *  Created on: Mar 7, 2017
 *      Author: bknery
 */

#include <iostream>
#include "colored_rectangle.h"

ColoredRectangle::ColoredRectangle() :
  Rectangle(0, 0, 2, 1), color_("white") {}

ColoredRectangle::ColoredRectangle(double x, double y, double width, double height, std::string color) :
  Rectangle(x, y, width, height), color_(color) {}

std::string ColoredRectangle::getColor() const {
  return color_;
}

void ColoredRectangle::setColor(std::string color) {
  color_ = color;
}

void ColoredRectangle::draw() const {
  Rectangle::draw();
  std::cout << "  color: " << color_ << std::endl;
}
