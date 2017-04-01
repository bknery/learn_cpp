/*
 * double_mechanism.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef DOUBLE_MECHANISM_H_
#define DOUBLE_MECHANISM_H_

#include <string>
#include <iostream>
#include "digital_mechanism.h"
#include "analog_mechanism.h"

class DoubleMechanism : public DigitalMechanism, public AnalogMechanism {
public:
  DoubleMechanism(double base_price = 0, std::string time = "12:00",
                  int date = 2017, std::string alarm = "OFF");
  virtual void showType(std::ostream& out) const override;
  virtual void showDisplay(std::ostream& out) const override;
  virtual ~DoubleMechanism() {}
};

#endif /* DOUBLE_MECHANISM_H_ */
