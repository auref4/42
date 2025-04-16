#include "PmergeMe.hpp"

void	first_screen(std::deque<int>& deque)
{
	system("clear");
	std::string	welcome = "║ FORDJOHNSON ║ ";
	std::cout << std::endl;
	std::cout << "╔═════════════╗" << std::endl;
	for (int i = 0; i < static_cast<int>(welcome.size()); i++)
	{
		usleep(100000);
		std::cout << welcome[i] << std::flush;
	}
	usleep(1000000);
	std::cout << std::endl << std::endl;
	std::cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════"<< std::endl;
	std::cout << "║ UNSORTED LIST ❌" << std::endl;
	std::cout << "║" << std::endl;
	print_container(deque);
	usleep(300000);
}


void	second_screen(std::deque<int>& deque)
{
	std::string	sorting = " ⏳SORTING...⏳";
	std::cout << std::endl;
	for (int i = 0; i < static_cast<int>(sorting.size()); i++)
	{
		usleep(200000);
		std::cout << sorting[i] << std::flush;
	}
	usleep(2000000);
	std::cout << "\033[A" << "\033[2K" << std::flush;
	usleep(300000);
	check_sort(deque);
	usleep(2000000);
	std::cout << "╔═════════════════════════════════════════════════════════════════════════════════════════════════════" << std::endl;
	std::cout << "║ SORTED LIST ✅" << std::endl;
	std::cout << "║" << std::endl;
	print_container(deque);

}

void	third_screen(double d1, double d2, FordJohnson& fj)
{
	std::string	stats = " 📊 STATS 🔽";

	std::cout << std::endl << std::endl;
	for (int i = 0; i < static_cast<int>(stats.size()); i++)
	{
		usleep(200000);
		std::cout << stats[i] << std::flush;
	}
	usleep(200000);
	std::cout << std::endl << std::endl;
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
				std::cout << std::endl;
				std::cout << "UNSORTED ❌ IT = " << *it << ", IT+1 = " << *(it + 1) << std::endl << std::endl;
				return false;
			}
			it++;
		}
		i++;
	}
	std::cout << std::endl;
	std::cout << " ✔️  LIST CORRECTLY SORTED 🔽" << std::endl << std::endl;
	return true;
}
