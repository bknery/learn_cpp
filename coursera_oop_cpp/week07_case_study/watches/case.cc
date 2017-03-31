/*
 * case.cc
 *
 *  Created on: Mar 30, 2017
 *      Author: bknery
 */

#include "case.h"

Case::Case(const std::string& name, double base_price) :
  Accessory(name + " case", base_price) {}

