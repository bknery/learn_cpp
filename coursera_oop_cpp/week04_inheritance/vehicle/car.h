/*
 * car.h
 *
 *  Created on: Mar 8, 2017
 *      Author: bknery
 */

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include "vehicle.h"

class Car : public Vehicle {
public:
  Car();
  Car(std::string brand, unsigned int purchaseYear, float purchasePrice,
      float cylinderCapacity, unsigned int doors, unsigned int horsePower,
      float kilometers);
  void show(ostream& out) const;
  void calculatePrice();

protected:
  float cyclinderCapacity_;
  unsigned int doors_;
  unsigned int horsePower_;
  float kilometers_;

};



#endif /* CAR_H_ */
