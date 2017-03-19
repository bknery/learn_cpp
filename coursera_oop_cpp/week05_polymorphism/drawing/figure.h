/*
 * figure.h
 *
 *  Created on: Mar 18, 2017
 *      Author: bknery
 */

#ifndef FIGURE_H_
#define FIGURE_H_

class Figure {
public:
  virtual void show() const = 0;
  virtual Figure* copy() const = 0;
  virtual ~Figure() {}
};

#endif /* FIGURE_H_ */
