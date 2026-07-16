#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << "--- Create bureaucrats ---" << std::endl;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	manager("Manager", 40);
	Bureaucrat	intern("Intern", 150);

	std::cout << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;

	std::cout << "\n--- Create forms ---" << std::endl;
	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm		robot("Bender");
	PresidentialPardonForm	pardon("Arthur Dent");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n--- Try execute unsigned form ---" << std::endl;
	boss.executeForm(shrub);

	std::cout << "\n--- Sign forms ---" << std::endl;
	intern.signForm(shrub);
	boss.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);

	std::cout << "\n--- Execute with too low grade ---" << std::endl;
	intern.executeForm(shrub);
	manager.executeForm(robot);
	manager.executeForm(pardon);

	std::cout << "\n--- Execute successfully ---" << std::endl;
	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	return (0);
}