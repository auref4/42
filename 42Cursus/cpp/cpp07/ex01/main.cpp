#include "Iter.hpp"

void	printInt(int const &nb)
{
	std::cout << nb << std::endl;
}

void	printString(std::string const &str)
{
	std::cout << str << std::endl;
}

int	main(void)
{
	int			array1[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	std::string	array2[5] = {"je", "fais", "un", "test", "!"};

	std::cout << "TEST 1 : " << std::endl;
	iter(array1, 8, printInt);
	std::cout << std::endl;
	std::cout << "TEST 2 : " << std::endl;
	iter(array2, 5, printString);

	return 0;
}
