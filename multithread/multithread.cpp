// Multithread example
// file: multithread.cpp
// Author: Bruno Knopki Nery
#include "simple_thread.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 3;

int main() {

	std::vector<std::thread> threads;

    // Create and launch a thread
	for (int i = 0; i < num_threads; i++) {
		threads.push_back(std::thread(PrintThreadNum, i, 3));
	}

    // Join the thread with the main thread
	for (int i = 0; i < num_threads; i++) {
		threads[i].join();
	}

    return 0;
}
