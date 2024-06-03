#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a("A", 1);
	std::cout << a << std::endl;
	Bureaucrat	b("B", 150);
	std::cout << b << std::endl;
	std::cout << "TEST 1 :" << std::endl;
	try
	{
		Form	c("C", 12, 12);
		std::cout << c << std::endl;
		c.beSigned(a);
		std::cout << std::endl;
		std::cout << c << std::endl;
		c.beSigned(b);
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 2 :" << std::endl;
	try
	{
		Form	d("D", 12, 12);
		std::cout << d << std::endl;
		d.beSigned(b);
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 3 :" << std::endl;
	try
	{
		Form	e("E", 150, 1);
		std::cout << e << std::endl;
		e.beSigned(b);
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 4 :" << std::endl;
	try
	{
		Form	f("F", 0, 150);
		std::cout << f << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 5 :" << std::endl;
	try
	{
		Form	g("G", 1, 151);
		std::cout << g << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
