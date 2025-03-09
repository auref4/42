#include "FordJohnson.hpp"

void	manage(FordJohnson& fj)
{
	fj.recursive_sort(2);
}

int	main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return 0;
	}
	try
	{
		FordJohnson	fj(argv);

		std::cout << "before sort :" << std::endl;
		fj.print_container();
		std::cout << std::endl;
		manage(fj);
		std::cout << "after sort :" << std::endl;
		fj.print_container();
		if (fj.check_sort() == true)
			std::cout << "result : sorted!" << std::endl;
		else
			std::cout << "result : unsorted!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 1;
}
