#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print_lines();
void print_words();
void int_vector();

int main(){
	cout << "File's lines:\n";
	print_lines();
	cout << "\nFile's words:\n";
	print_words();
	int_vector();
}

void print_lines(){
	vector<string> v;
	ifstream in("file.txt");
	string line;
	while(getline(in, line))
		v.push_back(line);
	for(int i = 0; i < v.size(); i++)
		cout << i << ": " << v[i] << "\n";
}

void print_words(){
	vector<string> words;
	ifstream in("file.txt");
	string word;
	while(in >> word)
		words.push_back(word);
	for(int i = 0; i < words.size(); i++)
		cout << i << ": " << words[i] << "\n";
}

void int_vector(){
	vector<int> v;
	for(int i = 0; i < 10; i++)
		v.push_back(i);
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ", ";
	cout << endl;
	for(int i = 0; i < v.size(); i++)
		v[i] = v[i] * 10; // Assignment
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ", ";
	cout << endl;
} ///:~
