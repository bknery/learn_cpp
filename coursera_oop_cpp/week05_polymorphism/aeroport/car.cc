/*
 * car.cc
 *
 *  Created on: 9 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "car.h"

Car::Car() : Vehicle(), cyclinderCapacity_(1.0), doors_(5), horsePower_(80), kilometers_(0) {}

Car::Car(std::string brand, unsigned int purchaseYear, float purchasePrice,
         float cylinderCapacity, unsigned int doors, unsigned int horsePower,
         float kilometers) :
             Vehicle(brand, purchaseYear, purchasePrice),
             cyclinderCapacity_(cylinderCapacity),
             doors_(doors),
             horsePower_(horsePower),
             kilometers_(kilometers) {}

void Car::show(std::ostream& out) const {
  out << "---- Car ----" << std::endl;
  Vehicle::show(out);
  out << cyclinderCapacity_ << " liters, " << doors_ << " doors, "
      << horsePower_ << " HP, " << kilometers_ << " km." << std::endl;
}

void Car::calculatePrice() {

  float temp_price = purchasePrice_;

  // years
  unsigned int years_passed(2017 - purchaseYear_);

  for(unsigned int i = 0; i < years_passed; ++i) {
    temp_price = temp_price - (temp_price * 0.02);
  }

  // kms
  unsigned int km_10k = (unsigned int) kilometers_ / 10000;

  for(unsigned int i = 0; i < km_10k; ++i) {
    temp_price = temp_price - (temp_price * 0.05);
  }

  if ((brand_ == "Renault") || (brand_ == "Fiat")) {
    temp_price = temp_price - (temp_price * 0.10);
  }

  if ((brand_ == "Ferrari") || (brand_ == "Porsche")) {
    temp_price = temp_price + (temp_price * 0.20);
  }

  currentPrice_ = temp_price;
}
