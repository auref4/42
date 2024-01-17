#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class	Fixed
{
	public :

	Fixed();
	Fixed(int nb);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed&	operator=(Fixed const &rhs);
	Fixed	operator+(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private :

	int				m_nb;
	int const static fract = 8;
};

#endif
