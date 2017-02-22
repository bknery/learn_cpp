/*
 * main.cc
 *
 *  Created on: Feb 21, 2017
 *      Author: bknery
 */

#include <iostream>
#include "triangle.h"

int main() {
  float x1, y1, z1, x2, y2, z2, x3, y3, z3;

  std::cout << "Let's build a triangle." << std::endl;
  std::cout << "Please enter point 1:" << std::endl;
  std::cout << "x1: ";
  std::cin >> x1;
  std::cout << "y1: ";
  std::cin >> y1;
  std::cout << "z1: ";
  std::cin >> z1;

  std::cout << "Please enter point 2:" << std::endl;
  std::cout << "x2: ";
  std::cin >> x2;
  std::cout << "y2: ";
  std::cin >> y2;
  std::cout << "z2: ";
  std::cin >> z2;

  std::cout << "Please enter point 3:" << std::endl;
  std::cout << "x3: ";
  std::cin >> x3;
  std::cout << "y3: ";
  std::cin >> y3;
  std::cout << "z3: ";
  std::cin >> z3;

  // Create points instances
  Point3D point1(x1, y1, z1);
  Point3D point2(x2, y2, z2);
  Point3D point3(x3, y3, z3);

  // Create triangle instance
  Triangle triangle(point1, point2, point3);

  std::cout << "Triangle perimeter = " << triangle.perimeter() << std::endl;

  if (triangle.isIsosceles()) {
    std::cout << "This triangle is isosceles." << std::endl;
  } else {
    std::cout << "This triangle is not isosceles." << std::endl;
  }
}
