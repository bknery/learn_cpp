/*
 * stuffed_animal.h
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef STUFFED_ANIMAL_H_
#define STUFFED_ANIMAL_H_

#include "endangered.h"
#include "gadget.h"

class StuffedAnimal : public Endangered, public Gadget {
public:
  StuffedAnimal(std::string animalName, std::string gadgetName, std::string continent, int number, double price);
  void tag() const;
  ~StuffedAnimal();
};

#endif /* STUFFED_ANIMAL_H_ */
