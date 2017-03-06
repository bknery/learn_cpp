/*
 * circle.h
 *
 *  Created on: 15 de fev de 2017
 *      Author: bruno.nery
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
 public:
  Circle();

  Circle(double x, double y, double r);

  void getCenter(double& x, double& y) const;

  void getR(double& r) const;

  void setCenter(double x, double y);

  void setR(double r);

  double area() const;

  bool isIn(double x, double y) const;

  ~Circle();

 private:
  double x_;
  double y_;
  double r_;
};

#endif /* CIRCLE_H_ */
