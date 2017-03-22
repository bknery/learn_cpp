/*
 * endangered.cc
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "endangered.h"

Endangered::Endangered(std::string name, std::string continent, int number) :
  Animal(name, continent), number_(number) {
  std::cout << "New endangered animal" << std::endl;
}

void Endangered::show() const {
  std::cout << "There is no more than " << number_ << " animals of this species in the Earth." << std::endl;
}

Endangered::~Endangered() {
  std::cout << "Destructing endangered animal " << name_ << std::endl;
}
