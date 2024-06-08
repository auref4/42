#include "RobotomyRequestForm.hpp"

//CONSTRUCTORS

RobotomyRequestForm::RobotomyRequestForm() : m_target("Unknow"), AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : m_target("target"),
AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm assignement constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : m_target(src.m_target),
AForm(src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

//DESTRUCTOR

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//OPERATOR

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void) rhs;

	std::cout << "RobotomyRequestForm assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	this->checkRequirements(executor);
	std::cout << m_target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
