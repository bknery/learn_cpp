/*
 * accessory.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef ACCESSORY_H_
#define ACCESSORY_H_

#include <string>
#include "product.h"

class Accessory : public Product {
public:
  Accessory(const std::string& name, double base_price);
  virtual void show(std::ostream& out) const override;
  virtual ~Accessory() {}

private:
  const std::string name_;
};

#endif /* ACCESSORY_H_ */
