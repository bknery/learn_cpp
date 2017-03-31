/*
 * mechanism.cc
 *
 *  Created on: Mar 30, 2017
 *      Author: bknery
 */

#include "mechanism.h"

Mechanism::Mechanism(double base_price, std::string time) :
  Product(base_price), time_(time) {}
