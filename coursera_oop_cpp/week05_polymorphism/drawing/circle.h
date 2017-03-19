/*
 * form.h
 *
 *  Created on: Mar 18, 2017
 *      Author: bknery
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "figure.h"

class Circle : public Figure {
public:
  Circle(double r);
  Circle(const Circle& c);
  virtual void show() const override;
  virtual Figure* copy() const override;
  virtual ~Circle();

private:
  double r_;
};

#endif /* CIRCLE_H_ */
