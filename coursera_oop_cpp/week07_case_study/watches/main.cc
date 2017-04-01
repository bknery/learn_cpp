/*
 * main.cc
 *
 *  Created on: Mar 28, 2017
 *      Author: bknery
 */

#include <iostream>
#include "watch.h"
#include "strap.h"
#include "clasp.h"
#include "case.h"
#include "glass.h"
#include "analog_mechanism.h"
#include "digital_mechanism.h"
#include "double_mechanism.h"

int main() {

  AnalogMechanism analogCore(10, "22:24", 2009);
  DigitalMechanism digitalCore(20, "10:24 PM", "7:00 AM");
  DoubleMechanism doubleCore(30, "22:28", 2018, "7:30 AM");

  std::cout << "==== Mechanisms ====" << std::endl;

  std::cout << analogCore << std::endl << std::endl;
  std::cout << digitalCore << std::endl << std::endl;
  std::cout << doubleCore << std::endl << std::endl;

  std::cout << "==== Android Watch ====" << std::endl;

  Watch android(new DoubleMechanism(50, "22:32", 2019, "6:15 AM") ,10);

  android.add(new Strap("leather", 54.00));
  android.add(new Clasp("steel", 12.50));
  android.add(new Case("steel", 36.60));
  android.add(new Glass("quartz", 44.80));

  std::cout << android << std::endl;

  return 0;
}


