#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public :

	Fixed();
	Fixed(int const nb);
	Fixed(float const nb);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed&					operator=(Fixed const &rhs);
	Fixed					operator+(Fixed const &rhs);
	friend std::ostream&	operator<<(std::ostream &i, Fixed const &rhs);

	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private :

	int					m_nb;
	int const static	m_fract = 8;
};

#endif
