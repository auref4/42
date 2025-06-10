#include "Fixed.hpp"

Fixed::Fixed() : m_nb(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int nb) : m_nb(nb)
{
	std::cout<<"Constructor with int "<<m_nb<<" in parameter called"<<std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout<<"Copy constructor called"<<std::endl;

	*this = src;

	return ;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	std::cout<<"Copy assignement operator called"<<std::endl;
	this->m_nb = rhs.getRawBits();

	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	return (this->m_nb + rhs.getRawBits());
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;

	return (this->m_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->m_nb = raw;
}
