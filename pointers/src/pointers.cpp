// Hello World program
// file: hello_world.cpp
#include <iostream>

void f(int* p);

int main(){
	int x = 47;
	std::cout << "x = " << x << std::endl;
	std::cout << "&x = " << &x << std::endl;
	f(&x);
	std::cout << "x = " << x << std::endl;
}

void f(int* p){
	std::cout << "p = " << p << std::endl;
	std::cout << "*p = " << *p << std::endl;
	*p = 5;
	std::cout << "p = " << p << std::endl;
}
