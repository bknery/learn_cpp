/*
 * aeroport.cc
 *
 *  Created on: Mar 18, 2017
 *      Author: bknery
 */

#include "aeroport.h"

void Aeroport::addVehicle(Vehicle* vehicle) {
  vehicles_.push_back(vehicle);
}

void Aeroport::showVehicles(std::ostream& out) {
  for (auto const& vehicle : vehicles_) {
    vehicle->calculatePrice();
    vehicle->show(out);
  }
}

void Aeroport::emptyVehicles() {
  vehicles_.clear();
}

void Aeroport::deleteVehicles() {
  for (auto const& vehicle : vehicles_) {
    delete vehicle;
  }
  vehicles_.clear();
}

Aeroport::~Aeroport() {
  emptyVehicles();
}
