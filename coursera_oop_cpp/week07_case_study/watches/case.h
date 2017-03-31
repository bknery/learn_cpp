/*
 * case.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef CASE_H_
#define CASE_H_

#include "accessory.h"

class Case : public Accessory {
public:
  Case(const std::string& name, double base_price);
  virtual ~Case() {}
};

#endif /* CASE_H_ */
