#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void tryFind(T &container, int value)
{
	try
	{
		typename T::iterator it;

		it = easyfind(container, value);
		std::cout << "Found " << *it << std::endl;
	}
	catch (std::exception const &error)
	{
		std::cout << error.what() << ": " << value << std::endl;
	}
}

int main(void)
{
	std::vector<int> numbers;
	std::list<int> listNumbers;
	std::deque<int> dequeNumbers;

	for (int i = 0; i < 5; ++i)
	{
		numbers.push_back(i * 10);
		listNumbers.push_back(i + 1);
		dequeNumbers.push_back(42 - i);
	}
	tryFind(numbers, 20);
	tryFind(numbers, 21);
	tryFind(listNumbers, 4);
	tryFind(dequeNumbers, 40);

	return 0;
}
