#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

Base*	generate(void)
{
	srand(time(0));

	int	random = std::rand() % 3;

	if (random == 0)
		return new A();
	if (random == 1)
		return new B();
	if (random == 2)
		return new C();
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It's 'A' type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's 'B' type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's 'C' type" << std::endl;
	else
		std::cout << "Unknow type" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "It's 'A' type" << std::endl;
		return ;
	}
	catch (std::exception const& e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "It's 'B' type" << std::endl;
		return ;
	}
	catch (std::exception const& e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "It's 'C' type" << std::endl;
		return ;
	}
	catch (std::exception const& e)
	{
	}
	std::cout << "Unknow type" << std::endl;
}

int	main(void)
{
	Base *p = generate();

	identify(p);
	identify(*p);
	delete p;
}
