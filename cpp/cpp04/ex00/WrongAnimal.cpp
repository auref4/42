#include "WrongAnimal.hpp"

// CONSTRUCTOR

WrongAnimal::WrongAnimal() : m_type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : m_type(src.m_type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// DESTRUCTOR

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

// OPERATOR

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->m_type = rhs.m_type;
	return *this;
}

// MEMBER FUNCTIONS

std::string	WrongAnimal::getType(void) const
{
	return this->m_type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal noise" << std::endl;
}
