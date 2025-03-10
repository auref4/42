#include "FordJohnson.hpp"

bool	check_sort(std::deque<int>& deque)
{
	int	i = 0;

	while (i < static_cast<int>(deque.size()))
	{
		std::deque<int>::iterator it = deque.begin() + i;
		while (it < deque.end() - 1)
		{
			if (*it > *(it + 1))
			{
				std::cout << "result : unsorted ! it = " << *it << ", it+1 = " << *(it + 1) << std::endl;
				return false;
			}
			it++;
		}
		i++;
	}
	std::cout << "result : sorted !" << std::endl;
	return true;
}

void	manage(std::deque<int>& deque, std::vector<int>& vector)
{
	FordJohnson	fj;

	fj.recursive_sort(deque, 2);
	fj.recursive_sort(vector, 2);
}

void	print_container(std::deque<int>& deque, std::vector<int>& vector)
{
	std::cout << "dequeu = ";
	for (std::deque<int>::iterator	it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "vector = ";
	for (std::vector<int>::iterator	it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool	check_duplicates(std::deque<int>& deque)
{
	int	i = 0;

	while (i < static_cast<int>(deque.size() - 1))
	{
		int				nb = *(deque.begin() + i);
		std::deque<int>::iterator	it = deque.begin() + i + 1;
		while (it < deque.end())
		{
			if (nb == *it)
				return true;
			it++;
		}
		i++;
	}
	return false;
}

bool	init_container(std::deque<int>& deque, std::vector<int>& vector, char** argv)
{
	double	d;
	char*	endptr;

	for (int i = 1; argv[i]; i++)
	{
		d = strtod(argv[i], &endptr);
		if (*endptr != '\0' || d < 0)
		{
			std::cerr << "invalid inputs, arguments should be numbers between 0 and INT_MAX" << std::endl;
			return false;
		}
		if (d > INT_MAX)
		{
			std::cerr << "overflow detected !" << std::endl;
			return false;
		}		
		deque.push_back(static_cast<int>(d));
		vector.push_back(static_cast<int>(d));
	}
	if (check_duplicates(deque) == true)
	{
		std::cerr << "invalid inputs, duplicates are not accepted !" << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return 0;
	}
	std::deque<int>		deque;
	std::vector<int>	vector;

	if (init_container(deque, vector, argv) == false)
		return 0;
	std::cout << "before sort :" << std::endl;
	print_container(deque, vector);
	std::cout << std::endl;
	manage(deque, vector);
	std::cout << "after sort :" << std::endl;
	print_container(deque, vector);
	check_sort(deque);
	return 1;
}
