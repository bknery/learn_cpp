/*
 * square.h
 *
 *  Created on: Mar 19, 2017
 *      Author: bknery
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "figure.h"

class Square : public Figure {
public:
  Square(double side);
  Square(const Square& s);
  virtual void show() const override;
  virtual Figure* copy() const override;
  virtual ~Square();
private:
  double side_;
};

#endif /* SQUARE_H_ */
