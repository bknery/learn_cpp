/*
 * plane.cc
 *
 *  Created on: 9 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "plane.h"

Plane::Plane() : Vehicle(), type_("turbine"), flightHours_(0) {}

Plane::Plane(std::string brand, unsigned int purchaseYear, float purchasePrice,
             std::string type, unsigned int flightHours) :
                 Vehicle(brand, purchaseYear, purchasePrice),
                 type_(type),
                 flightHours_(flightHours) {}

void Plane::show(std::ostream& out) const {
  out << "---- " << type_ << " Plane ----" << std::endl;
  Vehicle::show(out);
  out << flightHours_ << " flight hours." << std::endl;
}

void Plane::calculatePrice() {

  float temp_price = purchasePrice_;

  unsigned int hours_1k = (unsigned int) flightHours_ / 1000;


  if (type_ == "turbine") {
    for(unsigned int i = 0; i < hours_1k; ++i) {
      temp_price = temp_price - (temp_price * 0.10);
    }
  }

  unsigned int hours_100 = (unsigned int) flightHours_ / 100;

  if (type_ == "helice") {
    for(unsigned int i = 0; i < hours_100; ++i) {
      temp_price = temp_price - (temp_price * 0.10);
    }
  }

  currentPrice_ = temp_price;
}
