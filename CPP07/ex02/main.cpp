#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main(void)
{
	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = static_cast<int>(i * 10);

	Array<int> copy(numbers);
	copy[0] = 42;
	std::cout << "numbers[0] = " << numbers[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;

	Array<std::string> words(3);
	words[0] = "deep";
	words[1] = "copy";
	words[2] = "test";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << words[i] << std::endl;

	Array<int> empty;
	std::cout << "empty size = " << empty.size() << std::endl;
	try
	{
		std::cout << numbers[5] << std::endl;
	}
	catch (std::exception const &error)
	{
		std::cout << error.what() << std::endl;
	}
	return 0;
}
