/*
 * circle.h
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "figure.h"

class Circle : public Figure {
public:
  Circle(double x = 0, double y = 0, double r = 1);
  double area() const;
  double getR() const;
  void setR(double r);

private:
  double r_;
};



#endif /* CIRCLE_H_ */
