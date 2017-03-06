/*
 * magic_paper.cc
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#include "magic_paper.h"

MagicPaper::MagicPaper() {
  age_ = 0;
  money_ = 0;
}

int MagicPaper::writePaper(unsigned int age, unsigned int money) {
  age_ = age;
  money_ = money;
  return 0;
}

void MagicPaper::readPaper(unsigned int& age, unsigned int& money) {
  age = age_;
  money = money_;
}
