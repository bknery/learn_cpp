// Simple Thread class
// file: simple_thread.cpp
// Author: Bruno Knopki Nery
#include "simple_thread.h"
#include <iostream>

void PrintThreadNum(int thread_num, int times) {

	for (int i = 0; i < times; i++) {
		std::cout << "Hello Thread " << thread_num
					<< ", iteraction " << i << std::endl;
	}
}

