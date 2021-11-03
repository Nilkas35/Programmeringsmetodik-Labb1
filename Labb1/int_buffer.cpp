/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* int_buffer.cpp, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-03
* implementerings fil för int_buffer till labb 1
*/

#include "int_buffer.h"


	int_buffer::int_buffer(size_t size)
	{
	}

	int_buffer::int_buffer(const int* source, size_t size)
	{
	}

	int_buffer::int_buffer(const int_buffer& rhs)
	{
	}

	int_buffer::int_buffer(int_buffer&& rhs)
	{
	}

	int_buffer& int_buffer::operator=(const int_buffer& rhs)
	{
		// TODO: insert return statement here
	}

	int_buffer& int_buffer::operator=(int_buffer&& rhs)
	{
		// TODO: insert return statement here
	}

	int& int_buffer::operator[](size_t index)
	{
		// TODO: insert return statement here
	}

	const int& int_buffer::operator[](size_t index) const
	{
		// TODO: insert return statement here
	}

	size_t int_buffer::size() const
	{
		return size_t();
	}

	int* int_buffer::begin()
	{
		return nullptr;
	}

	int* int_buffer::end()
	{
		return nullptr;
	}

	const int* int_buffer::begin() const
	{
		return nullptr;
	}

	const int* int_buffer::end() const
	{
		return nullptr;
	}

	void int_buffer::swap(int_buffer& lhs, int_buffer& rhs)
	{
	}

	int_buffer::~int_buffer()
	{
	}
