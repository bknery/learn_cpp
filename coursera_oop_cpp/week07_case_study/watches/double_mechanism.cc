/*
 * double_mechanism.cc
 *
 *  Created on: Mar 30, 2017
 *      Author: bknery
 */

#include "double_mechanism.h"

DoubleMechanism::DoubleMechanism(double base_price, std::string time, int date, std::string alarm) :
  Mechanism(base_price, time), DigitalMechanism(base_price, time, alarm),
  AnalogMechanism(base_price, time, date) {}
