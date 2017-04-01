/*
 * mechanism.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef MECHANISM_H_
#define MECHANISM_H_

#include <iostream>
#include <string>
#include "product.h"

class Mechanism : public Product {
public:
  Mechanism(double base_price = 0, std::string time = "12:00");
  virtual void show(std::ostream& out) const override final;
  virtual void showType(std::ostream& out) const = 0;
  virtual void showDisplay(std::ostream& out) const;
  virtual ~Mechanism() {}

private:
  std::string time_;
};

#endif /* MECHANISM_H_ */
