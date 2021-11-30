/**
* Laboration 1: Dynamisk minneshantering, RAII och merge, Programmeringsmetodik, dt047g
* Niklas Nordström - nino1701
* Labb1.cpp, skapandedatum: 2021-11-01, Senaste redigering: 2021-11-25
* Main-fil till labb 1
*/

#include <iostream>
#include <chrono>
#include <algorithm>
#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buf);
void time_selection_sort(int* arr, const int size);
void time_merge_sort(int* arr, const int size);
void time_std_sort(int* arr, const int size);
void compare_sort(int* arr, const int size);


int main()
{
	//f(int_buffer(10));
	const int size = 40000;

	int arr[size]{};

	for (int i = 0; i < size; ++i)
		arr[i] = rand();

	compare_sort(arr, size);

	return 0;
}

void f(int_buffer buf)
{
	int count = 1;
	std::cout << "\n Filling the buffer with values now\n";
	for (int* i = buf.begin(); i != buf.end(); i++) {
		*i = count;
		count++;
	}
	std::cout << " Buffer is now filled with values\n";

	std::cout << "\n This is the first for print loop:\n";
	for (const int* i = buf.begin(); i != buf.end(); i++)
		std::cout << i << "\n";

	std::cout << "\n This is  auto e:\n";
	for (auto e : buf)
		std::cout << e << "\n";
}

void time_selection_sort(int* arr, const int size) {

	int_buffer selection_buffer = int_buffer(arr, size);
	auto selection_start = std::chrono::steady_clock::now();
	selection_buffer.selection_sort(selection_buffer);
	auto selection_end = std::chrono::steady_clock::now();
	auto selection_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(selection_end - selection_start);
	std::cout << "Selection sort time: " << selection_elapsed.count() << " ms\n";
}

void time_merge_sort(int* arr, const int size)
{
	auto merge_start = std::chrono::steady_clock::now();
	auto sorted = int_sorted(arr, size);
	auto merge_end = std::chrono::steady_clock::now();
	auto merge_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(merge_end - merge_start);
	std::cout << "Merge sort time: " << merge_elapsed.count() << " ms\n";
}

void time_std_sort(int* arr, const int size)
{

	auto test = int_buffer(arr, size);
	std::cout << "Is buffer sorted before: " << test.is_sorted() << std::endl;
	auto std_start = std::chrono::steady_clock::now();
	std::sort(arr, arr + size);
	auto std_end = std::chrono::steady_clock::now();
	auto std_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std_end - std_start);

	test = int_buffer(arr, size);
	std::cout << "Is buffer sorted after: " << test.is_sorted() << std::endl;


	std::cout << "std sort time: " << std_elapsed.count() << " ms\n";
}

void compare_sort(int* arr, const int size)
{
	std::cout << "Selection sort\n";
	time_selection_sort(arr, size);
	std::cout << "\nMerg sort\n";
	time_merge_sort(arr, size);
	std::cout << "\nstd sort\n";
	time_std_sort(arr, size);
}
