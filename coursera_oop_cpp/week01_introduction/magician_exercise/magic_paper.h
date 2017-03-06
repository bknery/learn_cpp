/*
 * magic_paper.h
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#ifndef MAGIC_PAPER_H_
#define MAGIC_PAPER_H_

class MagicPaper {
 public:
  MagicPaper();
  int writePaper(unsigned int age, unsigned int money);
  void readPaper(unsigned int& age, unsigned int& money);

 private:
  unsigned int age_;
  unsigned int money_;
};

#endif /* MAGIC_PAPER_H_ */
