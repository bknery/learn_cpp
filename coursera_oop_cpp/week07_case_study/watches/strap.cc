/*
 * strap.cc
 *
 *  Created on: Mar 29, 2017
 *      Author: bknery
 */

#include "strap.h"

Strap::Strap(const std::string& name, double base_price) :
  Accessory(name + " strap", base_price) {}
