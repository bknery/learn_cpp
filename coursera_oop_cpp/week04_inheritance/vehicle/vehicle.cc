/*
 * vehicle.cc
 *
 *  Created on: 9 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "vehicle.h"

Vehicle::Vehicle() : brand_("No Brand"), purchaseYear_(2000), purchasePrice_(10000), currentPrice_(0) {}

Vehicle::Vehicle(std::string brand, unsigned int purchaseYear, float purchasePrice)
  : brand_(brand), purchaseYear_(purchaseYear), purchasePrice_(purchasePrice), currentPrice_(0) {}

void Vehicle::show(std::ostream& out) const {
  out << "Brand: " << brand_ << ", purchase year: " << purchaseYear_
      << ", purchase price: " << purchasePrice_ << std::endl;
  out << "Current price: " << currentPrice_ << std::endl;
}

void Vehicle::calculatePrice() {

  unsigned int years_passed(2017 - purchaseYear_);
  float temp_price = purchasePrice_;

  for(unsigned int i = 0; i < years_passed; ++i) {
    temp_price = temp_price - (temp_price * 0.01);
  }

  currentPrice_ = temp_price;
}

