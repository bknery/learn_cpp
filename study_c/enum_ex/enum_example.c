/*
 * enum_example.c
 *
 *  Created on: Aug 30, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>

#include "car.h"

int main() {
  car_type car1 = {500, "Honda", WHITE};
  car_type car2 = {600, "Citroen", BLUE};

  printf("car 1:\n");
  car_show(&car1);
  car_set_color(&car1, RED);
  printf("\ncar 1:\n");
  car_show(&car1);

  printf("\ncar 2:\n");
  car_show(&car2);
  car_set_brand(&car2, "Volks Wagen");
  printf("\ncar 2:\n");
  car_show(&car2);
}
