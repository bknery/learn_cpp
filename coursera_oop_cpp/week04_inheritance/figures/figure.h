/*
 * figure.h
 *
 *  Created on: Mar 6, 2017
 *      Author: bknery
 */

#ifndef FIGURE_H_
#define FIGURE_H_

#include <string>

class Figure {
public:
  Figure();
  Figure(std::string color);
  std::string getColor() const;
  void setColor(std::string color);

protected:
  std::string color_;
};

#endif /* FIGURE_H_ */
