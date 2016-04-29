#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void copy_my_file();
void print_my_file();

int main(){
	copy_my_file();
	print_my_file();
}

void copy_my_file(){
	ifstream in("file.txt");
	ofstream out("file2.txt");
	string s;

	while(getline(in, s))
		out << s << "\n";
}

void print_my_file(){
	ifstream in("file.txt");
	string s, line;
	while(getline(in, line))
		s += line + "\n";
	cout << s;
}
