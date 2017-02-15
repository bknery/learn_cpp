/*
 * main.cc
 *
 *  Created on: 15 de fev de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "Rectangle.h"

int main(void) {
  Rectangle rect;
  rect.setHeight(2);
  rect.setWidth(3);
  std::cout << "rectangle height = " << rect.getHeight() << std::endl;
  std::cout << "rectangle width = " << rect.getWidth() << std::endl;
  std::cout << "rectangle area = " << rect.area() << std::endl;
  return 0;
}
