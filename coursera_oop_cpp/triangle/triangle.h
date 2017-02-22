/*
 * triangle.h
 *
 *  Created on: Feb 21, 2017
 *      Author: bknery
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "point_3D.h"

class Triangle {
public:
	Triangle(Point3D p1, Point3D p2, Point3D p3);
	double perimeter() const;
	bool isIsosceles() const;

private:
	Point3D p1_;
	Point3D p2_;
	Point3D p3_;
};

#endif /* TRIANGLE_H_ */
