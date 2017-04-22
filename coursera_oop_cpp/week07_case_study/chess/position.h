/*
 * position.h
 *
 *  Created on: Apr 21, 2017
 *      Author: bknery
 */

#ifndef POSITION_H_
#define POSITION_H_

#include <iostream>
#include "color.h"

class Position {
public:
  Position(int x = 1, int y = 1);
  int getX() const {return x_;}
  int getY() const {return y_;}
  void setX(int x);
  void setY(int y);
  void show(std::ostream& out) const;
private:
  int x_;
  int y_;
};

#endif /* POSITION_H_ */
