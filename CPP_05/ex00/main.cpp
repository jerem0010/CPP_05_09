#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "--- Valid bureaucrat ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;

		bob.incrementGrade();
		std::cout << bob << std::endl;

		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Too high construction ---" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Too low construction ---" << std::endl;
	try
	{
		Bureaucrat john("John", 151);
		std::cout << john << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Increment too far ---" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;
		boss.incrementGrade();
		std::cout << boss << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Decrement too far ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		std::cout << intern << std::endl;
		intern.decrementGrade();
		std::cout << intern << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}