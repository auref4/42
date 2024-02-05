#include "Point.hpp"

Fixed	area(Point const p1, Point const p2, Point const p3)
{
	Fixed	nb1_x = p1.getX();
	Fixed	nb1_y = p1.getY();
	Fixed	nb2_x = p2.getX();
	Fixed	nb2_y = p2.getY();
	Fixed	nb3_x = p3.getX();
	Fixed	nb3_y = p3.getY();
	Fixed	res;

	res = (nb1_x - nb3_x) * (nb2_y - nb3_y) - (nb2_x - nb3_x) * (nb1_y - nb3_y);
	if (res < 0)
		res = res * -1;
	return res;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abc = area(a, b, c);
	Fixed	pab = area(point, a, b);
	Fixed	pbc = area(point, b, c);
	Fixed	pac = area(point, a, c);

	if ((pab == 0) | (pbc == 0) | (pac == 0))
		return false;
	if	(pab + pbc + pac == abc)
		return true;
	return false;
}
