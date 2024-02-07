#include "Dog.hpp"

// OPERATOR

Dog::Dog() : Animal()
{
	m_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	m_type = src.m_type;
	std::cout << "Dog copy constructor called" << std::endl;
}

// DESTRUCTOR

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

// OPERATOR

Dog&	Dog::operator=(Dog const &rhs)
{
	m_type = rhs.m_type;
	return *this;
}

// MEMBER FUNCTIONS

std::string	Dog::getType(void) const
{
	return this->m_type;
}

void	Dog::makeSound(void) const
{
	std::cout << "Waouuf!" << std::endl;
}
