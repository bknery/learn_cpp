/*
 * Rectangle.h
 *
 *  Created on: 15 de fev de 2017
 *      Author: bruno.nery
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle {
 public:
  Rectangle();
  double area() const;
  void setHeight(double h);
  void setWidth(double w);
  double getHeight() const;
  double getWidth() const;
  ~Rectangle();

 private:
  double width;
  double height;
};

#endif /* RECTANGLE_H_ */
