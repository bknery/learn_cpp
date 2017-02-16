/*
 * main.cc
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "magician.h"

int main() {
  Spectator spectator;
  spectator.enterRoom();

  // ask  the spectator age and check it
  while (true) {
    int age = 0;
    std::cout << "How old is the spectator? ";
    std::cin >> age;
    if ((age < 0) || (age > 150)) {
      // age is not ok
      std::cout << "Please enter an age between 0 and 150." << std::endl;
    } else {
      // age is ok
      // set the age
      spectator.setAge(age);
      break;
    }
  }

  // ask  the spectator money and check it
  while (true) {
    int money = 0;
    std::cout << "How much money the spectator has in his pocket? (<100) ";
    std::cin >> money;
    if ((money < 0) || (money > 100)) {
      // money is not ok
      std::cout << "Please enter a number between 0 and 100." << std::endl;
    } else {
      // age is ok
      // set the age
      if (spectator.setMoney(money) == 0) {
        std::cout << "[Spectator] (I'm here)" << std::endl;
        break;
      }
    }
  }

  // create the magician instance and pass the spectator
  Magician magician;
  // start magic
  magician.startMagic(spectator);
}
