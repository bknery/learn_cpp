#include <iostream>

int main(){
	bool quit = false;
	while(quit == false){
		std::cout << "Select a, b, c, or q to quit: ";
		char response;
		std::cin >> response;
		switch(response){
			case 'a':
				std::cout << "Your choice is 'a'\n";
				break;
			case 'b':
				std::cout << "Your choice is 'b'\n";
				break;
			case 'c':
				std::cout << "Your choice is 'c'\n";
				break;
			case 'q':
				std::cout << "Quit\n";
				quit = true;
				break;
			default:
				std::cout << "Please selectt a, b, c or q.\n";
				break;
		}
	}
}
