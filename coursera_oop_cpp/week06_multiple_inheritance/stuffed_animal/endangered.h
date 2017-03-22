/*
 * endangered.h
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef ENDANGERED_H_
#define ENDANGERED_H_

#include "animal.h"

class Endangered : public Animal {
public:
  Endangered(std::string name, std::string continent, int number);
  void show() const;
  ~Endangered();

protected:
  int number_;
};

#endif /* ENDANGERED_H_ */
