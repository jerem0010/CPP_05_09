#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	weak("Weak guy", 150);

	AForm* shrub = intern.makeForm("shrubbery creation", "home");
	AForm* robot = intern.makeForm("robotomy request", "Bender");
	AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
	AForm* unknown = intern.makeForm("coffee request", "Office");

	std::cout << std::endl;

	if (shrub)
	{
		std::cout << *shrub << std::endl;
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
	}

	std::cout << std::endl;

	if (robot)
	{
		std::cout << *robot << std::endl;
		boss.signForm(*robot);
		boss.executeForm(*robot);
		boss.executeForm(*robot);
	}

	std::cout << std::endl;

	if (pardon)
	{
		std::cout << *pardon << std::endl;
		weak.signForm(*pardon);
		weak.executeForm(*pardon);
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
	}

	delete shrub;
	delete robot;
	delete pardon;
	delete unknown;

	return (0);
}