/*
 * main.cc
 *
 *  Created on: 9 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include <vector>
#include "car.h"
#include "plane.h"

int main() {
  std::vector<Car> garage;
  std::vector<Plane> hangar;
  garage.push_back(Car("Peugeot", 1998, 147325.79, 2.5, 5, 180.0, 12000));
  garage.push_back(Car("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
  garage.push_back(Car("Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000));
  hangar.push_back(Plane("Cessna", 1972, 1230673.90, "helice", 250));
  hangar.push_back(Plane("Nain Connu", 1992, 4321098.00, "turbine", 1300));
  for (auto car : garage) {
    car.calculatePrice();
    car.show(std::cout);
  }
  for (auto plane : hangar) {
    plane.calculatePrice();
    plane.show(std::cout);
  }
  return 0;
}
