#include "BitcoinExchange.hpp"

int	main(int agrc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	BitcoinExchange	btc;
	return 1;
}
