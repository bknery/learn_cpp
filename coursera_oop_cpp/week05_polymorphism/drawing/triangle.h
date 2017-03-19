/*
 * triangle.h
 *
 *  Created on: Mar 18, 2017
 *      Author: bknery
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "figure.h"

class Triangle : public Figure {
public:
  Triangle(double base = 1.0, double height = 2.0);
  Triangle(const Triangle& t);
  virtual void show() const override;
  virtual Figure* copy() const override;
  virtual ~Triangle();

private:
  double base_;
  double height_;
};

#endif /* TRIANGLE_H_ */
