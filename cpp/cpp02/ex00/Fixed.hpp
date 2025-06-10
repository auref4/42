#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public :

	Fixed();									//Canonical
	Fixed(int nb);
	Fixed(Fixed const &src);					//Canonical
	~Fixed();									//Canonical

	Fixed&	operator=(Fixed const &rhs);		//Canonical
	Fixed	operator+(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private :

	int					m_nb;
	int const static	m_fract = 8;
};

#endif
