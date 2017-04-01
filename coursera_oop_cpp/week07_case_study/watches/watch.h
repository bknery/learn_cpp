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
  Watch(Mechanism* p_mechanism, double base_price);
  void add(Accessory* p_accessory);
  virtual double price() const override;
  virtual void show(std::ostream& out) const override;
  virtual ~Watch();

private:
  std::unique_ptr<Mechanism> core_;
  std::vector<std::unique_ptr<Accessory>> accessories_;
};

#endif /* WATCH_H_ */
