/*
 * main.cc
 *
 *  Created on: Mar 19, 2017
 *      Author: bknery
 */

#include <iostream>
#include "drawing.h"
#include "square.h"
#include "triangle.h"
#include "circle.h"

int main() {
  Drawing drawing;
  drawing.addFigure(Triangle(3,4));
  drawing.addFigure(Square(2));
  drawing.addFigure(Triangle(6,1));
  drawing.addFigure(Circle(12));
  std::cout << std::endl << "Showing the drawing: " << std::endl;
  drawing.show();
}
