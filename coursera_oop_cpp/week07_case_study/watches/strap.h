/*
 * strap.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef STRAP_H_
#define STRAP_H_

#include "accessory.h"

class Strap : public Accessory {
public:
  Strap(const std::string& name, double base_price);
  virtual ~Strap() {}
};

#endif /* STRAP_H_ */
