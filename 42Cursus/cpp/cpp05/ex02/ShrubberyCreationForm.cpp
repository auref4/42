#include "ShrubberyCreationForm.hpp"

//CONSTRUCTORS

ShrubberyCreationForm::ShrubberyCreationForm() : m_target("Unknow"), AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : m_target("target"),
AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreationForm assignement constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : m_target(src.m_target),
AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

//DESTRUCTOR

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//OPERATOR

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void) rhs;

	std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	this->checkRequirements(executor);
	std::cout << m_target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
