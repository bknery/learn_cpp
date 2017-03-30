/*
 * clasp.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef CLASP_H_
#define CLASP_H_

#include "accessory.h"

class Clasp : public Accessory {
public:
  Clasp(const std::string& name, double base_price);
  virtual ~Clasp() {}
};

#endif /* CLASP_H_ */
