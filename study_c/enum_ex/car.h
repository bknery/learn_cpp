/*
 * car.h
 *
 *  Created on: Aug 30, 2017
 *      Author: bknery
 */

#ifndef CAR_H_
#define CAR_H_

#define CAR_MAX_BRAND_SIZE 40

typedef enum color {
  WHITE,
  RED,
  GREEN,
  BLUE,
  BLACK
} color_e_type;

typedef struct car {
  int power;
  char brand[CAR_MAX_BRAND_SIZE];
  color_e_type color;
} car_type;

void car_show(car_type *c);
void car_set_color(car_type *c, color_e_type color);
void car_set_brand(car_type *c, const char *brand);

#endif /* CAR_H_ */
