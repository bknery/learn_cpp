/*
 * piece.h
 *
 *  Created on: Apr 21, 2017
 *      Author: bknery
 */

#ifndef PIECE_H_
#define PIECE_H_

#include "position.h"
#include "color.h"

class Piece {
public:
  Piece(const Position& position, const Color& color = WHITE);
  virtual bool move(const Position& position) = 0;
  virtual void show(std::ostream& out) const;
  virtual ~Piece();
private:
  Position position_;
  const Color color_;
};

#endif /* PIECE_H_ */
