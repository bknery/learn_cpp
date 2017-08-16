#include <iostream>
#include <stdio.h>

void f(int* p);

int main(){
	int x = 47;

    int y = 21;
    int *ptr = &y;

	std::cout << "x = " << x << std::endl;
	std::cout << "&x = " << &x << std::endl;
	f(&x);
	std::cout << "x = " << x << std::endl;

    printf("Pointers test:\n");
    printf("y = %d\n", y);
    printf("ptr = %p\n", ptr);
    printf("&y = 0x%p\n", &y);
    printf("*ptr = %d\n", *ptr);

}

void f(int* p){
	std::cout << "p = " << p << std::endl;
	std::cout << "*p = " << *p << std::endl;
	*p = 5;
	std::cout << "p = " << p << std::endl;
}
