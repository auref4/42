#include "Fixed.hpp"

// CONSTRUCTORS

Fixed::Fixed() : m_nb(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int const nb) : m_nb(nb<<m_fract)
{
	std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(float const nb) : m_nb(roundf(nb * (1<<m_fract)))
{
	std::cout<<"Float constructor called"<<std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout<<"Copy constructor called"<<std::endl;

	*this = src;

	return ;
}

// DESTRUCTOR

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

// OPERATORS

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	std::cout<<"Copy assignement operator called"<<std::endl;

	this->m_nb = rhs.getRawBits();

	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	std::cout<<"Addition operator called"<<std::endl;

	return (this->m_nb + rhs.getRawBits());
}

// MEMBER FUNCTIONS

float	Fixed::toFloat(void) const
{
	return (float)(this->m_nb) / (1<<m_fract);
}

int	Fixed::toInt(void) const
{
	return (m_nb>>m_fract);
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

// OPERATOR OSTREAM

std::ostream&	operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();

	return (o);
}
