/*
 * figure.h
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#ifndef FIGURE_H_
#define FIGURE_H_

#include <string>

class Figure {
public:
  Figure(double x = 0, double y = 0);
  double getX() const;
  double getY() const;
  void setX(double x);
  void setY(double y);
  void drawCenter() const;

protected:
  double x_;
  double y_;
};

#endif /* FIGURE_H_ */
