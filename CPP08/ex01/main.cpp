#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

static void printSpan(Span const &span)
{
	std::cout << "shortest: " << span.shortestSpan() << std::endl;
	std::cout << "longest: " << span.longestSpan() << std::endl;
}

int main(void)
{
	Span subject(5);

	subject.addNumber(6);
	subject.addNumber(3);
	subject.addNumber(17);
	subject.addNumber(9);
	subject.addNumber(11);
	printSpan(subject);

	try
	{
		subject.addNumber(42);
	}
	catch (std::exception const &error)
	{
		std::cout << error.what() << std::endl;
	}

	try
	{
		Span empty(1);
		empty.addNumber(7);
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (std::exception const &error)
	{
		std::cout << error.what() << std::endl;
	}

	std::vector<int> values;
	for (int i = 0; i < 10000; ++i)
		values.push_back(i * 3);

	Span big(values.size());
	big.addNumbers(values.begin(), values.end());
	printSpan(big);

	return 0;
}
