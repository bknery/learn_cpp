/*
 * aeroport.h
 *
 *  Created on: Mar 18, 2017
 *      Author: bknery
 */

#ifndef AEROPORT_H_
#define AEROPORT_H_

#include <vector>
#include "vehicle.h"

class Aeroport {
public:
  void showVehicles(std::ostream& out);
  void addVehicle(Vehicle* vehicle);
  void emptyVehicles();
  void deleteVehicles();
  ~Aeroport();
private:
  std::vector<Vehicle*> vehicles_;
};

#endif /* AEROPORT_H_ */
