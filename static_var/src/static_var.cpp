#include <iostream>

void func(void);

int main(){
	for(int x = 0; x < 10; x++)
		func();
}

void func(void){
	static int i = 0;
	std::cout << "i = " << i++ << std::endl;
}
