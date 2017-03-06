/*
 * spectator.cc
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#include "spectator.h"
#include <iostream>

Spectator::Spectator() {
  age_ = 0;
  money_ = 0;
}

void Spectator::enterRoom() const {
  std::cout << "[Spectator] (I've entered the room)" << std::endl;
}

int Spectator::setAge(unsigned int age) {
  if (age > 150) {
    return -1;
  } else {
    age_ = age;
    return 0;
  }
}

int Spectator::setMoney(unsigned int money) {
  if (money > 100) {
    return -1;
  } else {
    money_ = money;
    return 0;
  }
}

void Spectator::writePaper(MagicPaper& paper) {
  paper.writePaper(age_, money_);
  std::cout << "[Spectator] (I've written on the paper)" << std::endl;
}

void Spectator::showPaper(MagicPaper& paper, Assistant& assistant) const {
  std::cout << "[Spectator] (I am showing the paper)" << std::endl;
  assistant.readCalculateAnnounce(paper);
}
