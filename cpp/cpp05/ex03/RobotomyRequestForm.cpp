#include "RobotomyRequestForm.hpp"

//CONSTRUCTORS

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", "Unknow", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequest", target, 72, 45)
{
	std::cout << "RobotomyRequestForm assignement constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkRequirements(executor);
	std::srand(std::time(0));
	int	random = std::rand();
	if (random % 2 == 0)
		std::cout << "The " << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy of " << this->getTarget() << " failed" <<std::endl;
}
