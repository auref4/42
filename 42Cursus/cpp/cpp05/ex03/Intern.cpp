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

