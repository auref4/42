#include "FordJohnson.hpp"

int	main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return 0;
	}
	try
	{
		FordJohnson	fj_algo(argv);

		std::cout << "before sort :" << std::endl;
		fj_algo.print_container();
		std::cout << std::endl;
		fj_algo.sort();
		std::cout << "after sort :" << std::endl;
		fj_algo.print_container();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 1;
}
