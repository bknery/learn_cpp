/*
 * assistant.h
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#ifndef ASSISTANT_H_
#define ASSISTANT_H_

#include "magic_paper.h"

class Assistant {
 public:
  Assistant();
  int readCalculateAnnounce(MagicPaper& paper);
  unsigned int getResult() const { return result_; }

 private:
  unsigned int result_;
};

#endif /* ASSISTANT_H_ */
