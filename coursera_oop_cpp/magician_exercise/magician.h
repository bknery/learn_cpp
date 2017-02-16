/*
 * magician.h
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#ifndef MAGICIAN_H_
#define MAGICIAN_H_

#include "assistant.h"
#include "magic_paper.h"
#include "spectator.h"

class Magician {
 public:
  Magician();
  void startMagic(Spectator& spectator);
  void callSpectator(Spectator& spectator) const;
  void guess(int result) const;
  void announceMagicResult(unsigned int assistantResult) const;

 private:
  MagicPaper paper_;
  Assistant assistant_;
};

#endif /* MAGICIAN_H_ */
