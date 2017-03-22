/*
 * stuffed_animal.cc
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "stuffed_animal.h"

StuffedAnimal::StuffedAnimal(std::string animalName, std::string gadgetName, std::string continent, int number, double price) :
  Endangered(animalName, continent, number), Gadget(gadgetName, price) {
  std::cout << "New stuffed animal" << std::endl;
}

void StuffedAnimal::tag() const {
  std::cout << "Hello" << std::endl;
  Gadget::show();
  Animal::show();
  Endangered::show();
  Gadget::showPrice();
  std::cout << std::endl;
}

StuffedAnimal::~StuffedAnimal() {
  std::cout << "Destructing stuffed animal" << std::endl;
}
