#include <iostream>
#include <cstdlib>
using namespace std;

void dec_hex();
void concat();
void input();
void call_system_prog();

int main(){
	dec_hex();
	concat();
	input();
	call_system_prog();
}

void dec_hex(){
    cout << "decimal: " << dec << 15 << endl;
	cout << "hexa: " << hex << 15 << endl;
	cout << "float: " << 3.14159 << endl;
	cout << "char: " << char(33) << endl;
}

void concat(){
	cout << "concat 1 "
		"concat 2 "
		"concat 3 "
		"concat 4.\n";
}

void input(){
	int number;
	cout << "Enter a decimal number: ";
	cin >> number;
	cout << "Number in hexadecimal = 0x"
		<< hex << number << endl;
}

void call_system_prog(){
	system("ls -l");
}
