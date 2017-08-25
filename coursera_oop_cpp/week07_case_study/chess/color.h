/*
 * color.h
 *
 *  Created on: Apr 21, 2017
 *      Author: bknery
 */

#ifndef COLOR_H_
#define COLOR_H_

enum Color {BLACK, WHITE};

std::ostream& operator<<(std::ostream& out, const Color& color);

#endif /* COLOR_H_ */
