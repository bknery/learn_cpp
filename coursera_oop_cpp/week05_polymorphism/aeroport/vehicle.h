/*
 * vehicle.h
 *
 *  Created on: Mar 8, 2017
 *      Author: bknery
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <iostream>

class Vehicle {
public:
  Vehicle();
  Vehicle(std::string brand, unsigned int purchaseYear, float purchasePrice);
  virtual void show(std::ostream& out) const;
  virtual void calculatePrice();
  virtual ~Vehicle() {}

protected:
  std::string brand_;
  unsigned int purchaseYear_;
  float purchasePrice_;
  float currentPrice_;
};



#endif /* VEHICLE_H_ */
