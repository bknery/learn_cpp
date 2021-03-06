/*
 * analog_mechanism.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef ANALOG_MECHANISM_H_
#define ANALOG_MECHANISM_H_

#include <iostream>
#include <string>
#include "mechanism.h"

class AnalogMechanism : public virtual Mechanism {
public:
  AnalogMechanism(double base_price = 0, std::string time = "12:00", int date = 2017);
  virtual void showType(std::ostream& out) const override;
  virtual void showDisplay(std::ostream& out) const override;
  virtual ~AnalogMechanism() {}

protected:
  int date_;
};

#endif /* ANALOG_MECHANISM_H_ */
