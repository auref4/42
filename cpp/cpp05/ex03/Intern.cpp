#include "Intern.hpp"

//CONSTRUCTOR

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	*this = src;

	std::cout << "Intern copy constructor called" << std::endl;
}

//DESTRUCTOR

Intern::~Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

//OPERATOR

Intern&	Intern::operator=(Intern const &rhs)
{
	(void) rhs;

	std::cout << "Intern assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

AForm*	Intern::makeForm(std::string const name, std::string const target) const
{
	std::string	name_list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm*	(Intern::*pmf[3])(std::string const target) const =
	{
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	int	i = 0;
	while (i < 3 && name != name_list[i])
		i++;
	if (i < 3)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*pmf[i])(target);
		}
		else
			throw Intern::IncorrectName();
}

AForm*	Intern::makeShrubberyCreationForm(std::string const target) const
{
	return	new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobotomyRequestForm(std::string const target) const
{
	return	new RobotomyRequestForm(target);
}

AForm*	Intern::makePresidentialPardonForm(std::string const target) const
{
	return	new PresidentialPardonForm(target);
}

//EXCEPTION

const char*	Intern::IncorrectName::what() const throw()
{
	return "No Form matched with this name";
}
