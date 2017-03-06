/*
 * spectator.h
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#ifndef SPECTATOR_H_
#define SPECTATOR_H_

#include "assistant.h"
#include "magic_paper.h"

class Spectator {
 public:
  Spectator();
  void enterRoom() const;
  void writePaper(MagicPaper& paper);
  void showPaper(MagicPaper& paper, Assistant& assistant) const;
  int setAge(unsigned int age);
  int setMoney(unsigned int money);
  unsigned int getAge() const { return age_; };
  unsigned int getMoney() const { return money_; };

 private:
  unsigned int age_;
  unsigned int money_;
};

#endif /* SPECTATOR_H_ */
