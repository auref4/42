#include "Dog.hpp"

// OPERATOR

Dog::Dog() : Animal()
{
	this->m_type = "Dog";
	this->m_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	this->m_type = src.m_type;
	this->m_brain = new Brain(*src.m_brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

// DESTRUCTOR

Dog::~Dog()
{
	delete this->m_brain;
	std::cout << "Dog destructor called" << std::endl;
}

// OPERATOR

Dog&	Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->m_type = rhs.m_type;
		*this->m_brain = *rhs.m_brain;
	}
	std::cout << "Dog operator '=' called" << std::endl;
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
