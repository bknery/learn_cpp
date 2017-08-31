/*
 * car.c
 *
 *  Created on: Aug 30, 2017
 *      Author: bknery
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.h"

void car_show(car_type *c) {
  printf("Car info:\n");
  printf("  brand: %s\n", c->brand);
  printf("  power: %d HP\n", c->power);
  printf("  color: ");
  switch(c->color) {
    case WHITE:
      printf("white");
      break;
    case RED:
      printf("red");
      break;
    case GREEN:
      printf("green");
      break;
    case BLUE:
      printf("blue");
      break;
    case BLACK:
      printf("black");
      break;
    default:
      printf("undefined");
      break;
  }
  printf("\n");
}

void car_set_color(car_type *c, color_e_type color) {
  c->color = color;
}

void car_set_brand(car_type *c, const char *brand) {
  strcpy(c->brand, brand);
}


