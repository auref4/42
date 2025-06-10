#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	a("A", 1);
	std::cout << a << std::endl;
	Bureaucrat	b("B", 150);
	std::cout << b << std::endl;
	Bureaucrat	c("C", 12);
	std::cout << "TEST 1 :" << std::endl;
	try
	{
		PresidentialPardonForm	p("House");
		RobotomyRequestForm		r("House");
		ShrubberyCreationForm	s("House");
		std::cout << std::endl;
		p.beSigned(a);
		std::cout << std::endl;
		a.executeForm(p);
		std::cout << std::endl;
		r.beSigned(a);
		std::cout << std::endl;
		a.executeForm(r);
		std::cout << std::endl;
		s.beSigned(a);
		std::cout << std::endl;
		a.executeForm(s);
		std::cout << std::endl;
		b.executeForm(p);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 2 :" << std::endl;
	try
	{
		PresidentialPardonForm	p("House");
		std::cout << std::endl;
		a.executeForm(p);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 3 :" << std::endl;
	try
	{
		PresidentialPardonForm	p("House");
		std::cout << std::endl;
		p.beSigned(c);
		std::cout << std::endl;
		c.executeForm(p);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 4 :" << std::endl;
	try
	{
		PresidentialPardonForm	p("House");
		std::cout << std::endl;
		p.beSigned(c);
		std::cout << std::endl;
		a.executeForm(p);
		std::cout << std::endl;
		p.beSigned(a);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
