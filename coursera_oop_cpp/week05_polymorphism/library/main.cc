/*
 * main.cc
 *
 *  Created on: 21 de mar de 2017
 *      Author: bruno.nery
 */

#include <iostream>
#include "library.h"
#include "book.h"
#include "romance.h"
#include "police_romance.h"
#include "illustrated_book.h"

int main () {
  Library library;

  library.addBook(new Book("Macbeth", "Shakespeare", 125, false));
  library.addBook(new Book("The Girl on the Train", "Paula Hawkins", 307, true));
  library.addBook(new Romance("Love Story", "Eric Segal", 399, false, false));
  library.addBook(new Romance("Steve Jobs", "Walter Isaacson", 402, true, true));
  library.addBook(new PoliceRomance("Mr. Perfect", "Linda Howard", 450, true));
  library.addBook(new IllustratedBook("Alice Adventures", "Andre Gagon", 200, false));

  library.show(std::cout);
  library.deleteBooks();

  return 0;
}
