#include "IMateriaSource.hpp"

//OPERATOR

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &src)
{
	(void) src;

	std::cout << "IMateriaSource copy constructor called" << std::endl;
}

//DESTRUCTOR

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource destructor called" << std::endl;
}

//OPERATOR

IMateriaSource&	IMateriaSource::operator=(IMateriaSource const &rhs)
{
	(void) rhs;

	std::cout << "IMateriaSource operator '=' called" << std::endl;
	return *this;
}
