/*
 * glass.cc
 *
 *  Created on: Mar 30, 2017
 *      Author: bknery
 */

#include "glass.h"

Glass::Glass(const std::string& name, double base_price) :
  Accessory(name + " glass", base_price) {}
