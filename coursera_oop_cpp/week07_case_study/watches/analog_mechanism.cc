/*
 * analog_mechanism.cc
 *
 *  Created on: Mar 30, 2017
 *      Author: bknery
 */

#include "analog_mechanism.h"

AnalogMechanism::AnalogMechanism(double base_price, std::string time, int date) :
  Mechanism(base_price, time), date_(date) {}
