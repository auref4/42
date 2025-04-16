#include "FordJohnson.hpp"
#include "PmergeMe.hpp"

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

void	manage(std::deque<int>& deque, std::vector<int>& vector)
{
	FordJohnson	fj;
	clock_t		start;
	clock_t		end;
	
	first_screen(deque);

	start = clock();
	fj.sort(deque);
	end = clock();
	double d1 = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	double d2 = static_cast<double>((end - start) % CLOCKS_PER_SEC) * 1e6 / CLOCKS_PER_SEC;

	start = clock();
	fj.sort(vector);
	end = clock();
	double d3 = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	double d4 = static_cast<double>((end - start) % CLOCKS_PER_SEC) * 1e6 / CLOCKS_PER_SEC;

	second_screen(deque);
	third_screen(d1 + d2 / 1e6, d3 + d4 / 1e6, fj);
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
	manage(deque, vector);
	return 1;
}
