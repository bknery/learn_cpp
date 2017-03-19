/*
 * drawing.h
 *
 *  Created on: Mar 19, 2017
 *      Author: bknery
 */

#ifndef DRAWING_H_
#define DRAWING_H_

#include <vector>
#include "figure.h"

class Drawing {
public:
  void addFigure(const Figure& figure);
  void show() const;
  ~Drawing();

private:
  std::vector<Figure*> figures_;
};

#endif /* DRAWING_H_ */
