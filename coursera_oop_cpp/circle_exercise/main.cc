/*
 * main.cc
 *
 *  Created on: 15 de fev de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "circle.h"

int main() {
  Circle circle1(5, 4, 2);
  double r = 0;
  circle1.getR(r);
  std::cout << "Circle 1 r = " << r << std::endl;

  double x = 0;
  double y = 0;
  circle1.getCenter(x, y);
  std::cout << "Circle 1 center: x = " << x << ", y = " << y << std::endl;

  std::cout << "Circle 1 area = " << circle1.area() << std::endl;

  std::cout << "point(6, 5) is ";
  if (circle1.isIn(6, 5) == true) {
    std::cout << "IN" << std::endl;
  } else {
    std::cout << "OUT" << std::endl;
  }

  std::cout << "point(10, 10) is ";
  if (circle1.isIn(10, 10) == true) {
    std::cout << "IN" << std::endl;
  } else {
    std::cout << "OUT" << std::endl;
  }

  std::cout << std::endl;

  Circle circle2;
  circle2.setR(3);
  circle2.getR(r);
  std::cout << "Circle 2 r = " << r << std::endl;

  circle2.setCenter(7, 6);
  circle2.getCenter(x, y);
  std::cout << "Circle 2 center: x = " << x << ", y = " << y << std::endl;

  std::cout << "Circle 2 area = " << circle2.area() << std::endl;

  std::cout << "point(8, 7) is ";
  if (circle2.isIn(8, 7) == true) {
    std::cout << "IN" << std::endl;
  } else {
    std::cout << "OUT" << std::endl;
  }

  std::cout << "point(20, 20) is ";
  if (circle2.isIn(20, 20) == true) {
    std::cout << "IN" << std::endl;
  } else {
    std::cout << "OUT" << std::endl;
  }
}
