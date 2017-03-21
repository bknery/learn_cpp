/*
 * police_romance.h
 *
 *  Created on: 21 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef POLICE_ROMANCE_H_
#define POLICE_ROMANCE_H_

#include "romance.h"

class PoliceRomance : public Romance {
public:
  PoliceRomance(std::string title, std::string author, unsigned int pages, bool bestSeller);
  virtual double calculatePrice() const override;
  virtual void show(std::ostream& out) const override;
  ~PoliceRomance();
};

#endif /* POLICE_ROMANCE_H_ */
