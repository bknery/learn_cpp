/*
 * rectangle.h
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle : public Figure {
public:
  Rectangle(double width = 1, double height = 1);
  double area() const;
  double getWidth() const;
  double getHeight() const;
  void setWidth(double width);
  void setHeight(double height);

private:
  double width_;
  double height_;
};

#endif /* RECTANGLE_H_ */
