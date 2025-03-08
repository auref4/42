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
		fj_algo.manage();
		std::cout << "after sort :" << std::endl;
		fj_algo.print_container();
		if (fj_algo.check_sort() == true)
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
