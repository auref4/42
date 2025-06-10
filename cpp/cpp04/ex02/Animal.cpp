#include "Animal.hpp"

// CONSTRUCTOR

Animal::Animal() : m_type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src) : m_type(src.m_type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

// DESTRUCTOR

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// OPERATOR

Animal&	Animal::operator=(Animal const &rhs)
{
	this->m_type = rhs.m_type;
	return *this;
}

// MEMBER FUNCTIONS

std::string	Animal::getType(void) const
{
	return this->m_type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal noise" << std::endl;
}
