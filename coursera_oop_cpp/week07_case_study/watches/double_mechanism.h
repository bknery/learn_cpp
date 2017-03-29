/*
 * double_mechanism.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef DOUBLE_MECHANISM_H_
#define DOUBLE_MECHANISM_H_

#include "digital_mechanism.h"
#include "analog_mechanism.h"

class DoubleMechanism : public DigitalMechanism, public AnalogMechanism {

};

#endif /* DOUBLE_MECHANISM_H_ */
