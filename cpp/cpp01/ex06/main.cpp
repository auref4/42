#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	if (argc == 2)
	{
		std::string	level = (const char *)argv[1];
		harl.manage(level);
	}
	else
		std::cout << "Incorrect number of arguments" << std::endl;
	return 0;
}
