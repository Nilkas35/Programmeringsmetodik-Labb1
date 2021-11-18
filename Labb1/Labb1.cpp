/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* Labb1.cpp, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-17
* Main-fil till labb 1
*/

#include <iostream>
#include <chrono>
#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buf);
void selection_sort(int_buffer& source);


int main()
{
	srand((unsigned)time(0));
	constexpr int element_count = 400000;

	int source[element_count]{};
	int sources[element_count]{};

	for (size_t i = 0; i < element_count; ++i)
		source[i] = rand();

	for (size_t i = 0; i < element_count; ++i)
		sources[i] = rand();

	auto merge_start = std::chrono::steady_clock::now();
	int_sorted(source, element_count);
	auto merge_end = std::chrono::steady_clock::now();
	auto merge_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(merge_end - merge_start);

	std::cout << "Merge sort: " << merge_elapsed.count() << " ms" << std::endl;



	int_buffer source_buf(sources, element_count);

	//f(source_buf);

	auto merge_starts = std::chrono::steady_clock::now();
	selection_sort(source_buf);
	auto merge_ends = std::chrono::steady_clock::now();
	auto merge_elapseds = std::chrono::duration_cast<std::chrono::milliseconds>(merge_ends - merge_starts);

	std::cout << "selection sort: " << merge_elapseds.count() << " ms" << std::endl;



	//selection_sort(source_buf);
	//std::cout << "After sort\n";
	//f(source_buf);
}

void f(int_buffer buf)
{
	std::cout << "\n This is  first for print loop:\n";
	for (const int* i = buf.begin(); i != buf.end(); i++)
		std::cout << i << "\n";

	std::cout << "\n This is  auto e:\n";
	for (auto e : buf)
		std::cout << e << "\n";
}

void selection_sort(int_buffer& source) {
	for (auto i = source.begin(); i != source.end(); ++i) {
		int* min = i;
		for (auto j = i + 1; j != source.end(); ++j)
			if (*j < *min) min = j;

		std::swap(*i, *min);
	}
}