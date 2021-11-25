/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* Labb1.cpp, skapandedatum: 2021-11-17, Senaste redigering: 2021-11-25
* Header-fil för "int_sorted.cpp" till labb 1
*/

#ifndef INT_SORTED_H
#define INT_SORTED_H

#include <cstdlib>
#include "int_buffer.h"

class int_sorted {
private:
	int_buffer buffer;
public:

	int_sorted() = delete;

	int_sorted(const int* source, size_t size);

	size_t size() const;

	const int* insert(int value);

	const int* begin() const;

	const int* end() const;

	int_sorted sort(const int* begin, const	int* end);

	int_sorted merge(const int_sorted& merge_with) const;
};

#endif // INT_SORTED_H