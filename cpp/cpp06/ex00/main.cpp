#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc == 2)
		{
			std::string	arg(argv[1]);

			ScalarConverter::convert(arg);
		}
		else
			std::cout << "one arguments required" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
