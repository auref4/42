#include "Cat.hpp"

// OPERATOR

Cat::Cat() : Animal()
{
	this->m_type = "Cat";
	this->m_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	this->m_type = src.m_type;
	this->m_brain = new Brain(*src.m_brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

// DESTRUCTOR

Cat::~Cat()
{
	delete this->m_brain;
	std::cout << "Cat destructor called" << std::endl;
}

// OPERATOR

Cat&	Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->m_type = rhs.m_type;
		*this->m_brain = *rhs.m_brain;
	}
	return *this;
	std::cout << "Cat operator '=' called" << std::endl;
}

// MEMBER FUNCTIONS

std::string	Cat::getType(void) const
{
	return this->m_type;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaouu!" << std::endl;
}
