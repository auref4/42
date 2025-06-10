#include "PmergeMe.hpp"

void	first_screen(std::deque<int>& deque)
{
	system("clear");
	std::string	welcome = "║ FORDJOHNSON ║ ";
	std::cout << std::endl;
	std::cout << "╔═════════════╗" << std::endl;
	std::cout << "║ FORDJOHNSON ║" << std::endl << std::endl;
	std::cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════"<< std::endl;
	std::cout << "║ UNSORTED LIST ❌" << std::endl;
	std::cout << "║" << std::endl;
	print_container(deque);
}


void	second_screen(std::deque<int>& deque)
{
	check_sort(deque, 1);
	std::cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════" << std::endl;
	std::cout << "║ SORTED LIST ✅" << std::endl;
	std::cout << "║" << std::endl;
	print_container(deque);

}

void	third_screen(double d1, double d2, FordJohnson& fj)
{
	std::string	stats = " ~ STATS 📊 🔽";

	std::cout << std::endl << std::endl;
	std::cout << " ~ STATS 📊 🔽" << std::endl << std::endl; 
	std::cout << "╔═════════════════════════════════ " << std::endl;
	std::cout << "║ COMPARISONS : " << fj.get_comparisons() << std::endl << std::endl;
	std::cout << "╔═════════════════════════════════ " << std::endl;
	std::cout << "║   CONTAINER ↓ ║  TIME TO SORT ↓" << std::endl;
	std::cout << "║ ════════════════════════════════ " << std::endl;
	std::cout << "║     DEQUE     ║    " << d1 << "s" << std::endl;
	std::cout << "║ ════════════════════════════════ " << std::endl;
	std::cout << "║     VECTOR    ║    " << d2 << "s" << std::endl << std::endl;
}

void	print_container(std::deque<int>& deque)
{
	int	i = 0;
	
	std::cout << "║ ";
	for (std::deque<int>::iterator	it = deque.begin(); it != deque.end(); it++)
	{
		if (i == 35)
		{
			std::cout << std::endl;
			std::cout << "║ ";
			i = 0;
		}
		std::cout << *it << " ";
		i++;
	}
	std::cout << std::endl;
}

bool	check_sort(std::deque<int>& deque, int nb)
{
	int	i = 0;

	while (i < static_cast<int>(deque.size()))
	{
		std::deque<int>::iterator it = deque.begin() + i;
		while (it < deque.end() - 1)
		{
			if (*it > *(it + 1))
			{
				if (nb == 1)
				{
					std::cout << std::endl;
					std::cout << "UNSORTED ❌ IT = " << *it << ", IT+1 = " << *(it + 1) << std::endl << std::endl;
				}
				return false;
			}
			it++;
		}
		i++;
	}
	std::cout << std::endl;
	std::cout << " ~ LIST CORRECTLY SORTED ✔️ 🔽" << std::endl << std::endl;
	return true;
}
