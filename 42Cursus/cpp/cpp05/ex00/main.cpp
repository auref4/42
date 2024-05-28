#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a("Bob", 1);
	std::cout << a << std::endl;
	Bureaucrat	b("Clark", 150);
	std::cout << b << std::endl;
	Bureaucrat	c = b;
	std::cout << c << std::endl;
	try
	{
		Bureaucrat	d("Clint", 0);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	e("Zach", 151);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		a.incrementGrade();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		b.decrementGrade();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	f("test", 44);
		std::cout << f << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
