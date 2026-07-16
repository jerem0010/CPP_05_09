#include "PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

static int parsePositiveInteger(std::string const &text)
{
	char *end;
	long value;

	if (text.empty())
		throw std::runtime_error("Error");
	value = std::strtol(text.c_str(), &end, 10);
	if (*end != '\0' || value <= 0 || value > INT_MAX)
		throw std::runtime_error("Error");
	return static_cast<int>(value);
}

static std::vector<int> parseNumbers(int argc, char **argv)
{
	std::vector<int> numbers;

	for (int i = 1; i < argc; ++i)
		numbers.push_back(parsePositiveInteger(argv[i]));
	return numbers;
}

static void printVector(std::string const &label, std::vector<int> const &numbers)
{
	std::cout << label;
	for (std::vector<int>::size_type i = 0; i < numbers.size(); ++i)
		std::cout << " " << numbers[i];
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::vector<int> original;
	std::vector<int> vectorSorted;
	std::list<int> listInput;
	std::list<int> listSorted;
	PmergeMe sorter;
	std::clock_t start;
	std::clock_t end;
	double vectorTime;
	double listTime;

	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try
	{
		original = parseNumbers(argc, argv);
		printVector("Before:", original);
		start = std::clock();
		vectorSorted = sorter.sortVector(original);
		end = std::clock();
		vectorTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
		start = std::clock();
		for (std::vector<int>::const_iterator it = original.begin(); it != original.end(); ++it)
			listInput.push_back(*it);
		listSorted = sorter.sortList(listInput);
		end = std::clock();
		listTime = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
		vectorSorted.assign(listSorted.begin(), listSorted.end());
		printVector("After:", vectorSorted);
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << original.size()
			<< " elements with std::vector : " << vectorTime << " us" << std::endl;
		std::cout << "Time to process a range of " << original.size()
			<< " elements with std::list : " << listTime << " us" << std::endl;
	}
	catch (std::exception const &error)
	{
		std::cerr << error.what() << std::endl;
		return 1;
	}
	return 0;
}
