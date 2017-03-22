/*
 * animal.h
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {
public:
  Animal(std::string name, std::string continent);
  void show() const;
  ~Animal();

protected:
  std::string name_;
  std::string continent_;
};



#endif /* ANIMAL_H_ */
