/*
 * color.cc
 *
 *  Created on: Apr 21, 2017
 *      Author: bknery
 */

#include <iostream>
#include "color.h"

std::ostream& operator<<(std::ostream& out, const Color& color) {
  switch (color) {
    case WHITE:
      out << "white";
      break;
    case BLACK:
      out << "black";
      break;
    default:
      break;
  }
  return out;
}
