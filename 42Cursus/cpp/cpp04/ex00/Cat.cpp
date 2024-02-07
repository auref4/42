#include "Cat.hpp"

// OPERATOR

Cat::Cat() : Animal()
{
	m_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	m_type = src.m_type;
	std::cout << "Cat copy constructor called" << std::endl;
}

// DESTRUCTOR

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

// OPERATOR

Cat&	Cat::operator=(Cat const &rhs)
{
	m_type = rhs.m_type;
	return *this;
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
