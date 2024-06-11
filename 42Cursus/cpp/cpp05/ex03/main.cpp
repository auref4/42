#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern someRandomIntern;
	std::cout << "TEST1" << std::endl;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	delete rrf;
	std::cout << std::endl;
	std::cout << "TEST2" << std::endl;
	try
	{
		AForm*	ppf;
		ppf = someRandomIntern.makeForm("test", "test");
		std::cout << *ppf << std::endl;
		delete ppf;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST3" << std::endl;
	try
	{
		AForm*	scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "test");
		std::cout << *scf << std::endl;
		delete scf;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST4" << std::endl;
	try
	{
		AForm*	ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "test");
		std::cout << *ppf << std::endl;
		delete ppf;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
