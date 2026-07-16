#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*creators[3])(const std::string& target) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*creators[i])(target));
		}
	}

	std::cout << "Intern couldn't create " << formName << " because form does not exist" << std::endl;
	return (NULL);
}