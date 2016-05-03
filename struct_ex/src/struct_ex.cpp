#include <iostream>

typedef struct structure {
	char c;
	int i;
	float f;
	double d;
} structure;

void print_structure(structure* st_ptr);

int main(){
	structure s1, s2;
	structure* sp = &s1;
	// direct access
	s1.c = 'a';
	s1.i = 1;
	s1.f = 3.14;
	s1.d = 0.00093;
	std::cout << "s1 direct:\n";
	print_structure(&s1);

	// pointer access
	sp->c = 'b';
	sp->i = 2;
	sp->f = 4.15;
	sp->d = 0.00094;
	std::cout << "s1 pointer access:\n";
	print_structure(sp);

	// second structure pointer access
	sp = &s2;
	sp->c = 'c';
	sp->i = 3;
	sp->f = 5.16;
	sp->d = 0.00095;
	std::cout << "s2 pointer access:\n";
	print_structure(sp);

}

void print_structure(structure* st_ptr){
	std::cout << "c = " << st_ptr->c << std::endl;
	std::cout << "i = " << st_ptr->i << std::endl;
	std::cout << "f = " << st_ptr->f << std::endl;
	std::cout << "d = " << st_ptr->d << std::endl;
}
