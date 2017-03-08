/*
 * colored_retangle.h
 *
 *  Created on: 7 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef COLORED_RECTANGLE_H_
#define COLORED_RECTANGLE_H_

#include <string>
#include "rectangle.h"

class ColoredRectangle : public Rectangle {
public:
  ColoredRectangle();
  ColoredRectangle(double x, double y, double width, double height, std::string color);
  std::string getColor() const;
  void setColor(std::string color);
  void draw() const;

private:
  std::string color_;
};

#endif /* COLORED_RECTANGLE_H_ */
