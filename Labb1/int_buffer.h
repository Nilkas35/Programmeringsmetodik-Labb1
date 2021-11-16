/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* int_buffer.h, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-16
* Header-fil för "int_buffer.cpp" till labb 1
*/
#ifndef INT_BUFFER_H
#define INT_BUFFER_H

#include <cstdlib>

class int_buffer {
	size_t sz;
	int* value_ptr;
	void swap(int_buffer buffer1);

public:
	int_buffer() = delete;
	explicit int_buffer(size_t size); // size_t


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

	[[nodiscard]] const int* begin() const;
	[[nodiscard]] const int* end() const;


	[[nodiscard]] size_t size() const;
};

#endif // INT_BUFFER_H