/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordstr�m - nino1701
* int_buffer.h, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-25
* Header-fil f�r "int_buffer.cpp" till labb 1
*/

#ifndef INT_BUFFER_H
#define INT_BUFFER_H

#include <cstdlib>

class int_buffer {
	int sz;
	int* value_ptr;
	void swap(int_buffer& buffer);

public:
	int_buffer() = delete;
	explicit int_buffer(size_t size);

	int_buffer(const int* source, size_t size);

	int_buffer(const int_buffer& rhs); // copy
	int_buffer(int_buffer&& rhs) noexcept; // move

	~int_buffer();

	int_buffer& operator =(const int_buffer& rhs); // copy assign
	int_buffer& operator =(int_buffer&& rhs) noexcept; // move assign

	int& operator [](size_t index);
	const int& operator [](size_t index) const;

	int* begin();
	int* end();

	const int* begin() const;
	const int* end() const;

	size_t size() const;

	bool is_sorted();

	int_buffer selection_sort(int_buffer source);


};

#endif // INT_BUFFER_H