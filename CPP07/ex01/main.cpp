#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T const &value)
{
	std::cout << value << std::endl;
}

void increment(int &value)
{
	++value;
}

int main(void)
{
	int numbers[] = {0, 1, 2, 3, 4};
	std::string words[] = {"templates", "are", "compiled", "from", "headers"};
	std::string const const_words[] = {"const", "arrays", "work"};

	::iter(numbers, 5, increment);
	::iter(numbers, 5, print<int>);
	::iter(words, 5, print<std::string>);
	::iter(const_words, 3, print<std::string>);
	return 0;
}
