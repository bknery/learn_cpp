#include <iostream>

#define PRINT(STR, VAR) \
	std::cout << STR << " = " << VAR << std::endl

int main(){
	int i, j, k;
	std::cout << "Enter an integer: ";
	std::cin >> j;
	std::cout << "Enter another integer: ";
	std::cin >> k;
	PRINT("j", j);
	PRINT("k", k);
	i = j + k;
	PRINT("j + k", i);
}
