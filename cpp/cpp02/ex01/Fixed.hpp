#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public :

	Fixed();									//Canonical
	Fixed(int const nb);
	Fixed(float const nb);
	Fixed(Fixed const &src);					//Canonical
	~Fixed();									//Canonical

	Fixed&	operator=(Fixed const &rhs);		//Canonical
	Fixed	operator+(Fixed const &rhs);

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private :

	int					m_nb;
	int const static	m_fract = 8;
};

std::ostream&	operator<<(std::ostream &i, Fixed const &rhs);

#endif
