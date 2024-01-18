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

	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	Fixed&	operator=(Fixed const &rhs);
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	float			toFloat(void) const;
	int				toInt(void) const;
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	static Fixed	min(Fixed &rhs1, Fixed &rhs2);
	static Fixed	min(Fixed const &rhs1, Fixed const &rhs2);
	static Fixed	max(Fixed &rhs1, Fixed &rhs2);
	static Fixed	max(Fixed const &rhs1, Fixed const &rhs2);

	private :

	int					m_nb;
	int const static	m_fract = 8;
};

std::ostream&	operator<<(std::ostream &i, Fixed const &rhs);

#endif
