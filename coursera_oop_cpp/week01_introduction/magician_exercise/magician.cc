/*
 * magician.cc
 *
 *  Created on: 16 de fev de 2017
 *      Author: bruno.nery
 */

#include "magician.h"
#include <iostream>

Magician::Magician() {}

void Magician::startMagic(Spectator& spectator) {
  std::cout << "[Magician] (Let's start a little magic)" << std::endl;

  // Ask the spectator to write on the paper
  spectator.writePaper(paper_);

  // Spectator shows paper to assistant
  spectator.showPaper(paper_, assistant_);

  // Get result from assistant
  unsigned int assistantResult = assistant_.getResult();

  announceMagicResult(assistantResult);
}

void Magician::announceMagicResult(unsigned int assistantResult) const {
  unsigned int result = assistantResult + 115;
  std::cout << "[Magician] "
            << "I see that you are " << result << " years old "
            << "and you have " << result << " in your pocket." << std::endl;
}
