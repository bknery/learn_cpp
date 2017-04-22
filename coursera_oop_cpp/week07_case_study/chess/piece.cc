/*
 * piece.cc
 *
 *  Created on: Apr 21, 2017
 *      Author: bknery
 */

#include <iostream>
#include "piece.h"

Piece::Piece(const Position& position, const Color& color) :
  position_(position), color_(color) {}

void Piece::show(std::ostream& out) const {
  out << ", " << color_ << ", ";
  position_.show(out);
}
