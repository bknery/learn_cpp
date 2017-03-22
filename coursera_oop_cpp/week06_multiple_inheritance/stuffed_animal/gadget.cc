/*
 * gadget.cc
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "gadget.h"

Gadget::Gadget(std::string name, double price) : name_(name), price_(price) {
  std::cout << "New gadget" << std::endl;
}

void Gadget::show() const {
  std::cout << "My name is " << name_ << std::endl;
}

void Gadget::showPrice() const {
  std::cout << "Please buy me for " << price_ << " dollars and contribute to save me." << std::endl;
}

Gadget::~Gadget() {
  std::cout << "Destructing gadget " << name_ << std::endl;
}
