/*
 * rectangle.h
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "figure.h"

class Rectangle : public Figure {
public:
  Rectangle(double x = 0, double y = 0, double width = 2, double height = 1);
  double area() const;
  double getWidth() const;
  double getHeight() const;
  void setWidth(double width);
  void setHeight(double height);
  void draw() const;

protected:
  double width_;
  double height_;
};

#endif /* RECTANGLE_H_ */
