#include "AMateria.hpp"

//CONSTRUCTOR

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src) : m_type(src.m_type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : m_type(type)
{
	std::cout << "AMateria string constructor called" << std::endl;
}

//DESTRUCTOR

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

//OPERATOR

AMateria&	AMateria::operator=(AMateria const &rhs)
{
	std::cout << "AMateria operator '=' called" << std::endl;

	this->m_type = rhs.m_type;
	return *this;
}

//MEMBER FUNCTIONS

std::string const&	AMateria::getType(void) const
{
	return this->m_type;
}

void	AMateria::use(ICharacter &target)
{
	if (this->m_type == "ice")
		std::cout << "* shoots an ice bilt at " << target.getName() << " *" << std::endl;
	if (this->m_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
