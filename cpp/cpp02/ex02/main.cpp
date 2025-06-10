#include "Fixed.hpp"

int	main(void)
{
	std::cout << "main of 42" << std::endl;
	std::cout << std::endl;
	{
		Fixed		a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));

		std::cout<<a<<std::endl;
		std::cout<<++a<<std::endl;
		std::cout<<a<<std::endl;
		std::cout<<a++<<std::endl;
		std::cout<<a<<std::endl;
		std::cout<<b<<std::endl;
		std::cout<<Fixed::max(a, b)<<std::endl;
	}
	std::cout << std::endl;
	std::cout << "my main" << std::endl;
	std::cout << std::endl;
	{
		Fixed	a(5.05f);
		Fixed	b(2);
		Fixed	c;

		c = a / b;
		std::cout<<c<<std::endl;
		c = a + b;
		std::cout<<c<<std::endl;
		c = a - b;
		std::cout<<c<<std::endl;
		c = a * b;
		std::cout<<c<<std::endl;

	}
	return 0;
}
