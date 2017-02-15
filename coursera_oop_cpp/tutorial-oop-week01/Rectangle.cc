/*
 * Rectangle.cc
 *
 *  Created on: 15 de fev de 2017
 *      Author: bruno.nery
 */

#include "Rectangle.h"

Rectangle::Rectangle(void) {
  width = 0;
  height = 0;
}

void Rectangle::setHeight(double h) { height = h; }

void Rectangle::setWidth(double w) { width = w; }

double Rectangle::getHeight(void) const { return height; }

double Rectangle::getWidth(void) const { return width; }

double Rectangle::area() const { return width * height; }

Rectangle::~Rectangle(void) {}
