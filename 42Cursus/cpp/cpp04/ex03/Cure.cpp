#include "Cure.hpp"

//CONSTRUCTOR

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &src) :AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

//DESTRUCTOR

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

//OPERATOR

Cure&	Cure::operator=(Cure const &rhs)
{
	std::cout << "Cure operator '=' called" << std::endl;

	this->m_type = rhs.m_type;
	return *this;
}

//MEMBER FUNCTION

AMateria*	Cure::clone(void) const
{
	return new Cure();
}
