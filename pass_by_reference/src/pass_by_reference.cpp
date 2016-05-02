// Hello World program
// file: hello_world.cpp
#include <iostream>

void f(int &r);

int main(){
	int x = 47;
	std::cout << "x = " << x << std::endl;
	std::cout << "&x = " << &x << std::endl;
	f(x);
	std::cout << "x = " << x << std::endl;
}

void f(int &r){
	std::cout << "r = " << r << std::endl;
	std::cout << "&r = " << &r << std::endl;
	r = 5;
	std::cout << "r = " << r << std::endl;
}
