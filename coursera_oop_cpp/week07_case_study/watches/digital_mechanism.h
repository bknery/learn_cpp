/*
 * digital_mechanism.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef DIGITAL_MECHANISM_H_
#define DIGITAL_MECHANISM_H_

#include <iostream>
#include <string>
#include "mechanism.h"

class DigitalMechanism : public virtual Mechanism {
public:
  DigitalMechanism(double base_price = 0, std::string time = "12:00", std::string alarm = "OFF");
  virtual void showType(std::ostream& out) const override;
  virtual void showDisplay(std::ostream& out) const override;
  virtual ~DigitalMechanism() {}

protected:
  std::string alarm_;
};

#endif /* DIGITAL_MECHANISM_H_ */
