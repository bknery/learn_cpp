/*
 * animal.cc
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "animal.h"

Animal::Animal(std::string name, std::string continent) :
  name_(name), continent_(continent) {
  std::cout << "New protected animal" << std::endl;
}

void Animal::show() const {
  std::cout << "I am a " << name_
      << " and I live in " << continent_ << std::endl;
}

Animal::~Animal() {
  std::cout << "Destructing animal " << name_ << std::endl;
}
