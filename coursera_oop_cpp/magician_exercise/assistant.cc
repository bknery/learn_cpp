/*
 * assistant.cc
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#include "assistant.h"
#include <iostream>

Assistant::Assistant() { result_ = 0; }

int Assistant::readCalculateAnnounce(MagicPaper& paper) {
  unsigned int age = 0;
  unsigned int money = 0;

  // read the paper
  paper.readPaper(age, money);
  std::cout << "[Assistant] (I've read the paper)" << std::endl;
  std::cout << "[Assistant] (I am calculating)" << std::endl;

  // calculate
  result_ = (((age * 2) + 5) * 50) + money - 365;

  std::cout << "[Assistant] (The result is: " << result_ << std::endl;
  return 0;
}
