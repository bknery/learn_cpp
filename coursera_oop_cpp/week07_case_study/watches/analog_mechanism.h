/*
 * analog_mechanism.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef ANALOG_MECHANISM_H_
#define ANALOG_MECHANISM_H_

#include <string>
#include "mechanism.h"

class AnalogMechanism : public virtual Mechanism {
public:
  AnalogMechanism(double base_price = 0, std::string time = "12:00", int date = 2017);

private:
  int date_;
};

#endif /* ANALOG_MECHANISM_H_ */
