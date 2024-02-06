#include "Fixed.hpp"

// CONSTRUCTORS

Fixed::Fixed() : m_nb(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(int const nb) : m_nb(nb<<m_fract)
{
	std::cout<<"Int constructor called"<<" with value "<<m_nb<<std::endl;
}

Fixed::Fixed(float const nb) : m_nb(roundf(nb * (1<<m_fract)))
{
	std::cout<<"Float constructor called"<<" with value "<<m_nb<<std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
	return ;
}

//DESTRUCTOR

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

// OPERATORS

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (m_nb > rhs.m_nb);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (m_nb < rhs.m_nb);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (m_nb >= rhs.m_nb);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (m_nb <= rhs.m_nb);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (m_nb == rhs.m_nb);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (m_nb != rhs.m_nb);
}

Fixed&	Fixed::operator=(Fixed const &rhs)
{
	std::cout<<"Copy assignement operator called"<<std::endl;
	this->m_nb = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	std::cout<<"Addition operator called"<<std::endl;
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	std::cout<<"Substraction operator called"<<std::endl;
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	std::cout<<"Multiplication operator called"<<std::endl;
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	std::cout<<"Division operator called"<<std::endl;
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	this->m_nb += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->m_nb += 1;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	this->m_nb -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->m_nb -= 1;
	return (tmp);
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

Fixed	Fixed::min(Fixed &rhs1, Fixed &rhs2)
{
	return ((rhs1 < rhs2) ? rhs1 : rhs2);
}

Fixed	Fixed::min(Fixed const &rhs1, const Fixed &rhs2)
{
	return ((rhs1 < rhs2) ? rhs1 : rhs2);
}

Fixed	Fixed::max(Fixed &rhs1, Fixed &rhs2)
{
	return ((rhs1 > rhs2) ? rhs1 : rhs2);
}

Fixed	Fixed::max(Fixed const &rhs1, const Fixed &rhs2)
{
	return ((rhs1 > rhs2) ? rhs1 : rhs2);
}

// OPERATOR OSTREAM

std::ostream&	operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
