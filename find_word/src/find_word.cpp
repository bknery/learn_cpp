#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void count_word(string file, string find_str);
void print_file(string file);

int main(int argc, char *argv[]){
	if (argc <= 2){
		cout << "Usage: find_word <word> <file>\n";
		exit(1);
	}
	print_file(argv[2]);
	count_word(argv[2], argv[1]);
}

void count_word(string file, string find_str){
	ifstream in(file);
	string word;
	int i = 0;
	while(in >> word){
		if (word == find_str)
			i++;
	}
	cout << "Found " << i << " " + find_str + " words.\n";
}

void print_file(string file){
	ifstream in(file);
	string line;
	while(getline(in, line))
		cout << line + "\n";
}
