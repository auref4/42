#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vector_numbers;
	std::list<int>		list_numbers;

	for (int i = 0; i < 5; i++)
	{
		vector_numbers.push_back(i);
		list_numbers.push_back(i);
	}
	std::cout << "TEST 1" << std::endl;
	try
	{
		std::vector<int>::iterator	i = easyfind(vector_numbers, 2);
		std::cout << "(vector_numbers)Find : " << *i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 2" << std::endl;
	try
	{
		std::vector<int>::iterator	i = easyfind(vector_numbers, 4);
		std::cout << "(vector_numbers)Find : " << *i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 3" << std::endl;
	try
	{
		std::list<int>::iterator	i = easyfind(list_numbers, 3);
		std::cout << "(list_numbers)Find : " << *i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 4" << std::endl;
	try
	{
		std::vector<int>::iterator	i = easyfind(vector_numbers, 8);
		std::cout << "(vector_numbers)Find : " << *i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
