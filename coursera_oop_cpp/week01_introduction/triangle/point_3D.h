/*
 * point_3D.h
 *
 *  Created on: Feb 21, 2017
 *      Author: bknery
 */

#ifndef POINT_3D_H_
#define POINT_3D_H_

class Point3D {
 public:
  Point3D();
  Point3D(float x, float y, float z);
  void show() const;
  bool compare(const Point3D& point) const;
  float getX() const { return x_; }
  float getY() const { return y_; }
  float getZ() const { return z_; }
  void setX(float x);
  void setY(float y);
  void setZ(float z);
  double distance(const Point3D& point) const;

 private:
  float x_;
  float y_;
  float z_;
};

#endif /* POINT_3D_H_ */
