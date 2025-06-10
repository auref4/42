#include "PresidentialPardonForm.hpp"

//CONSTRUCTORS

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", "Unknow", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardon", target, 25, 5)
{
	std::cout << "PresidentialPardonForm assignement constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkRequirements(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
