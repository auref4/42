#include "Span.hpp"

int main()
{
	std::cout << "42 TEST :" << std::endl << std::endl;
	try
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "TEST 1:" << std::endl << std::endl;
	try
	{
		Span	sp = Span(4);

		sp.addMultipleNumbers(4);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "TEST 2:" << std::endl << std::endl;
	try
	{
		Span	sp = Span(4);

		sp.addMultipleNumbers(4);
		Span	sp2(sp);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "TEST 3:" << std::endl << std::endl;
	try
	{
		Span	sp = Span(4);

		sp.addMultipleNumbers(4);
		Span	sp2(1);

		sp2 = sp;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "TEST 4:" << std::endl << std::endl;
	try
	{
		Span	sp = Span(1);

		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "TEST 5:" << std::endl << std::endl;
	try
	{
		Span	sp = Span(1000);

		sp.addMultipleNumbers(1000);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
