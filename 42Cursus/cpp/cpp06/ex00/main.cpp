#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string	argument(argv[1]);

		ScalarConverter::convert(argument);
	}
	else
		std::cout << "one arguments required" << std::endl;
}
