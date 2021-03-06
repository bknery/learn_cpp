/*
 * product.h
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

class Product {
public:
  Product(double value = 0);
  virtual double price() const;
  virtual void show(std::ostream& out) const;
  virtual ~Product() = 0;

private:
  const double value_;
};

std::ostream& operator<<(std::ostream& out, const Product& product);

#endif /* PRODUCT_H_ */
