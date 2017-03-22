/*
 * main.cc
 *
 *  Created on: 22 de mar de 2017
 *      Author: bruno.nery
 */

#include "stuffed_animal.h"

int main () {
  StuffedAnimal panda("Panda","Ming","Asie", 200, 20.0);
  StuffedAnimal serpent("Cobra","Ssss","Asie", 500, 10.0);
  StuffedAnimal toucan("Toucan","Bello","Amérique", 1000, 15.0);
  panda.tag();
  serpent.tag();
  toucan.tag();
  return 0;
}


