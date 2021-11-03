/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* int_buffer.h, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-03
* Header-fil för "int_buffer.cpp" till labb 1
*/
#ifndef INT_BUFFER_H
#define INT_BUFFER_H

#include <cstdlib>

class int_buffer {
public:
	explicit int_buffer(size_t size); // size_t
	int_buffer(const int* source, size_t size);

	int_buffer(const int_buffer& rhs); // copy
	int_buffer(int_buffer&& rhs); // move

	int_buffer& operator =(const int_buffer& rhs); // copy assign
	int_buffer& operator =(int_buffer&& rhs); // move assign

	int& operator [](size_t index);

	const int& operator [](size_t index) const;

	size_t size() const;

	int* begin();
	int* end();

	const int* begin() const;
	const int* end() const;

	static void swap(int_buffer& lhs, int_buffer& rhs);

	~int_buffer();

private:
	int* buffer;
	int* buffer_end;


};

#endif // INT_BUFFER_H