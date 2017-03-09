/*
 * plane.h
 *
 *  Created on: Mar 8, 2017
 *      Author: bknery
 */

#ifndef PLANE_H_
#define PLANE_H_

#include <iostream>
#include "vehicle.h"

class Plane : public Vehicle {
public:
  Plane();
  Plane(std::string brand, unsigned int purchaseYear, float purchasePrice,
        std::string type, unsigned int flightHours);
  void show(std::ostream& out) const;
  void calculatePrice();

protected:
  std::string type_;
  unsigned int flightHours_;
};



#endif /* PLANE_H_ */
