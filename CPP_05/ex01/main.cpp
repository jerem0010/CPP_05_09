#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "--- Valid form creation ---" << std::endl;
	try
	{
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Invalid form too high ---" << std::endl;
	try
	{
		Form impossibleForm("Impossible Form", 0, 25);
		std::cout << impossibleForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Invalid form too low ---" << std::endl;
	try
	{
		Form uselessForm("Useless Form", 151, 25);
		std::cout << uselessForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Successful signature ---" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form secretForm("Secret Form", 20, 10);

		std::cout << boss << std::endl;
		std::cout << secretForm << std::endl;

		boss.signForm(secretForm);

		std::cout << secretForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Failed signature ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form secretForm("Secret Form", 20, 10);

		std::cout << intern << std::endl;
		std::cout << secretForm << std::endl;

		intern.signForm(secretForm);

		std::cout << secretForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}