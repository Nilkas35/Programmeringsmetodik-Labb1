/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* int_buffer.cpp, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-16
* implementerings fil för int_buffer till labb 1
*/

#include <algorithm>
#include "int_buffer.h"

int_buffer::int_buffer(size_t size) : sz(size), value_ptr(new int[size])
{
}

int_buffer::int_buffer(const int* source, size_t size) : sz(size), value_ptr(new int(size))
{
	std::copy(source, source + size, begin());
}

int_buffer::int_buffer(const int_buffer& rhs) : int_buffer(rhs.sz)
{
	std::copy(rhs.value_ptr, rhs.value_ptr + sz, value_ptr);
}

int_buffer::int_buffer(int_buffer&& rhs) noexcept :value_ptr(nullptr), sz(0)
{
}

int_buffer::~int_buffer()
{
	delete[] value_ptr;
}

int_buffer& int_buffer::operator=(const int_buffer& rhs)
{
	int_buffer tmp(rhs);
	swap(tmp);
	return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs) noexcept
{
	swap(rhs);
	return *this;
}



int& int_buffer::operator[](size_t index)
{
	return value_ptr[index];
}

const int& int_buffer::operator[](size_t index) const
{
	return value_ptr[index];
}

void int_buffer::swap(int_buffer rhs)
{
	std::swap(rhs.value_ptr, value_ptr);
	std::swap(rhs.sz, sz);
}

int* int_buffer::begin()
{
	return value_ptr;
}

int* int_buffer::end()
{
	return value_ptr + sz;
}

const int* int_buffer::begin() const
{
	return value_ptr;
}

const int* int_buffer::end() const
{
	return value_ptr + sz;
}

size_t int_buffer::size() const
{
	return sz;
}
