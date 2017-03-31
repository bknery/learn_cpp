/*
 * digital_mechanism.cc
 *
 *  Created on: Mar 30, 2017
 *      Author: bknery
 */

#include "digital_mechanism.h"

DigitalMechanism::DigitalMechanism(double base_price, std::string time, std::string alarm) :
  Mechanism(base_price, time), alarm_(alarm) {}

