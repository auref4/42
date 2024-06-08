#include "PresidentialPardonForm.hpp"

//CONSTRUCTORS

PresidentialPardonForm::PresidentialPardonForm() : m_target("Unknow"), AForm("PresidentialPardon", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : m_target("target"),
AForm("PresidentialPardon", 25, 5)
{
	std::cout << "PresidentialPardonForm assignement constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : m_target(src.m_target),
AForm(src)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

//DESTRUCTOR

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

//OPERATOR

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void) rhs;

	std::cout << "PresidentialPardonForm assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	this->checkRequirements(executor);
	std::cout << m_target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
