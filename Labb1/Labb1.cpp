/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* Labb1.cpp, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-16
* Main-fil till labb 1
*/

#include <iostream>
#include "int_buffer.h"

void f(int_buffer buf);


int main()
{
	f(int_buffer(10));
}

void f(int_buffer buf)
{
	std::cout << "\n This is  first for loop:\n";
	for (int* i = buf.begin(); i != buf.end(); i++) {
		*i = 1;
	}

	std::cout << "\n This is  first for print loop:\n";
	for (const int* i = buf.begin(); i != buf.end(); i++) {
		std::cout << i << "\n";
	}

	std::cout << "\n This is  auto e:\n";
	for (auto e : buf) {
		std::cout << e << "\n";
	}
}
