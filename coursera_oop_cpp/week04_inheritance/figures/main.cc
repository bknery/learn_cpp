/*
 * main.cc
 *
 *  Created on: Mar 7, 2017
 *      Author: bknery
 */

#include <iostream>
#include "colored_rectangle.h"
#include "circle.h"

int main() {
  ColoredRectangle rectangle(1, 1, 5, 4, "red");
  rectangle.draw();

  Circle circle(2, 6, 3);
  circle.draw();
}

