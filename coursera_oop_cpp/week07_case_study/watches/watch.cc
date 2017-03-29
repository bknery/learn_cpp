/*
 * watch.cc
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#include "watch.h"

void Watch::add(Accessory* p_accessory) {
  accessories_.push_back(std::unique_ptr<Accessory>(p_accessory));
}
