#ifndef	POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	public :

	Point();										//Canonical
	Point(float const x, float const y);
	Point(Point const &src);						//Canonical
	~Point();										//Canonical

	Point&		operator=(Point const &rhs);		//Canonical

	Fixed const	getX(void) const;
	Fixed const	getY(void) const;

	private:

	Fixed const	m_x;
	Fixed const	m_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
