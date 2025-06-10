#include "ICharacter.hpp"

//CONSTRUCTOR

ICharacter::ICharacter()
{
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &src)
{
	(void) src;

	std::cout << "ICharacter copy constructor called" << std::endl;
}

//DESTRUCTOR

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructor called" << std::endl;
}

//OPERATOR

ICharacter&	ICharacter::operator=(ICharacter const &rhs)
{
	(void) rhs;

	std::cout << "ICharacter operator '=' called" << std::endl;
	return *this;
}
