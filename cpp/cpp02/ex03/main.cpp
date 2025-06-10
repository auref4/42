#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	{
		Point	a(12, 12);
		Point	b(12, 44);
		Point	c(80, 24);
		Point	point(16, 24);

		if (bsp(a, b, c, point) == false)
			std::cout << "The point is out of the triangle" << std::endl;
		else
			std::cout << "The point is in the triangle" << std::endl;
	}
	std::cout << std::endl;
	{
		Point	a(12, 12);
		Point	b(12, 44);
		Point	c(80, 24);
		Point	point(8, 8);

		if (bsp(a, b, c, point) == false)
			std::cout << "The point is out of the triangle" << std::endl;
		else
			std::cout << "The point is in the triangle" << std::endl;
	}
	return 0;
}
