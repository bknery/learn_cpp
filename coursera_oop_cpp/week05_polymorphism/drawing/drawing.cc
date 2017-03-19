/*
 * drawing.cc
 *
 *  Created on: Mar 19, 2017
 *      Author: bknery
 */

#include "drawing.h"

void Drawing::addFigure(const Figure& figure) {
  figures_.push_back(figure.copy());
}

void Drawing::show() const {
  for (auto const& figure : figures_) {
    figure->show();
  }
}

Drawing::~Drawing() {
  for (auto const& figure : figures_) {
    delete figure;
  }
  figures_.clear();
}
