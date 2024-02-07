#include "WrongCat.hpp"

// OPERATOR

WrongCat::WrongCat() : WrongAnimal()
{
	m_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	m_type = src.m_type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

// DESTRUCTOR

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// OPERATOR

WrongCat&	WrongCat::operator=(WrongCat const &rhs)
{
	m_type = rhs.m_type;
	return *this;
}

// MEMBER FUNCTIONS

std::string	WrongCat::getType(void) const
{
	return this->m_type;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaouu!" << std::endl;
}
