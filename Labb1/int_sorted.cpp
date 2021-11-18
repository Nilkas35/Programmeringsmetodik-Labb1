/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* Labb1.cpp, skapandedatum: 2021-11-17, Senaste redigering: 2021-11-17
* Implementerings fil för int_sorted till labb 1
*/

#include <algorithm>
#include "int_sorted.h"

int_sorted::int_sorted() : buffer(int_buffer(0))
{
}

int_sorted::int_sorted(size_t size) : buffer(int_buffer(size))
{
}

int_sorted::int_sorted(const int* source, size_t size) : buffer(int_buffer(source, size))
{
	if (size > 1)
		*this = sort(begin(), end());
}

size_t int_sorted::size() const
{
	return buffer.size();
}

const int* int_sorted::insert(int value)
{
	buffer = merge(int_sorted(&value, 1)).buffer;
	return std::find(begin(), end(), value);
}

const int* int_sorted::begin() const
{
	return buffer.begin();
}

const int* int_sorted::end() const
{
	return buffer.end();
}

int_sorted int_sorted::sort(const int* begin, const int* end)
{
	if (begin == end) return int_sorted(nullptr, 0);
	if (begin == end - 1) return int_sorted(begin, 1);

	std::ptrdiff_t half = (end - begin) / 2; //	pointer diff type
	const int* mid = begin + half;

	return sort(begin, mid).merge(sort(mid, end));
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
	auto result_buffer = int_buffer(size() + merge_with.size());

	const int* a = begin();
	const int* b = merge_with.begin();
	int* iter = result_buffer.begin();

	while (a != end() && b != merge_with.end())
		*(iter++) = *((*a < *b) ? a++ : b++);

	while (a != end())
		*(iter++) = *(a++);

	while (b != merge_with.end())
		*(iter++) = *(b++);

	auto result = int_sorted();
	result.buffer = std::move(result_buffer);

	return result;
}
