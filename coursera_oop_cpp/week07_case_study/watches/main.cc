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

int main() {

  Watch android(0);

  android.add(new Strap("leather", 54.00));
  android.add(new Clasp("steel", 12.50));
  android.add(new Case("steel", 36.60));
  android.add(new Glass("quartz", 44.80));

  std::cout << "Watch android:" << std::endl;
  std::cout << android << std::endl;

  return 0;
}


