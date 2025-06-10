#include "Ice.hpp"

//CONSTRUCTOR

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

//DESTRUCTOR

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

//OPERATOR

Ice&	Ice::operator=(Ice const &rhs)
{
	std::cout << "Ice operator '=' called" << std::endl;

	this->m_type = rhs.m_type;
	return *this;
}

//MEMBER FUNCTION

AMateria*	Ice::clone(void) const
{
	return new Ice();
}
