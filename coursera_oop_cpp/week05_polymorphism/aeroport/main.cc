/*
 * main.cc
 *
 *  Created on: Mar 18, 2017
 *      Author: bknery
 */

#include <iostream>
#include "aeroport.h"
#include "car.h"
#include "plane.h"

int main() {
  Aeroport gva;
  gva.addVehicle(new Car("Peugeot", 1998, 147325.79, 2.5, 5, 180.0, 12000));
  gva.addVehicle(new Car("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
  gva.addVehicle(new Plane("Cessna", 1972, 1230673.90, "HELICES", 250));
  gva.addVehicle(new Plane("Nain Connu", 1992, 4321098.00, "REACTION", 1300));
  gva.addVehicle(new Car("Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000));
  gva.showVehicles(std::cout);

  gva.deleteVehicles();

  return 0;
}
