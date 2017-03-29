/*
 * watch.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef WATCH_H_
#define WATCH_H_

#include <memory>
#include <vector>
#include "product.h"
#include "mechanism.h"
#include "accessory.h"

class Watch : public Product {
public:

  void add(Accessory* p_accessory);

private:
  std::unique_ptr<Mechanism> core_;
  std::vector<std::unique_ptr<Accessory>> accessories_;
};

#endif /* WATCH_H_ */
