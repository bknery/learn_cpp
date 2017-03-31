/*
 * glass.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef GLASS_H_
#define GLASS_H_

#include "accessory.h"

class Glass : public Accessory {
public:
  Glass(const std::string& name, double base_price);
  virtual ~Glass() {}
};

#endif /* GLASS_H_ */
