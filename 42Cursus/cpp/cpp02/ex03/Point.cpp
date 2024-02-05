#include "Point.hpp"

//CONSTRUCTOR

Point::Point() : m_x(0), m_y(0)
{
}

Point::Point(float const x, float const y) : m_x(x), m_y(y)
{
}

Point::Point(Point const &src) : m_x(src.m_x), m_y(src.m_y)
{
}

//DESTRUCTOR

Point::~Point()
{
}

//OPERATOR

Point&	Point::operator=(Point const &rhs)
{
	(Fixed)this->m_x = rhs.getX();
	(Fixed)this->m_y = rhs.getY();
	return *this;
}

//MEMBER FUNCTIONS

Fixed const	Point::getX(void) const
{
	return this->m_x;
}

Fixed const	Point::getY(void) const
{
	return this->m_y;
}
