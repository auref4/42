#include "BitcoinExchange.hpp"

bool	open_files(std::ifstream& ifs1, std::ifstream& ifs2)
{
	if (ifs1.is_open() == false)
	{
		std::cerr << "Error : ifs1 can't be open" << std::endl;
		return false;
	}
	if (ifs2.is_open() == false)
	{
		std::cerr << "Error : ifs2 can't be open" << std::endl;
		ifs1.close();
		return false;
	}
	return true;
}

bool	check_line(std::string line)
{
	int	i = 0;

	while (line[i] && isdigit(line[i]))
		i++;
	if (i != 4 || line[i] != '.')
		return false;
	i++;
	while (line[i] && isdigit(line[i]))
		i++;
	if (i != 7 || line[i] != '.')
		return false;
	i++;
	while (line[i] && isdigit(line[i]))
		i++;
	if (i != 10 || line[i] != ' ')
		return false;
	return true;
}

bool	find_stock_data(std::ifstream& ifs1, std::ifstream& ifs2, BitcoinExchange& btcex)
{
	std::string	line;

	while (getline(ifs1, line))
	{
		if (check_line(line) == false)
			btcex.set_nb_error(1);
	}
}

int	main(int agrc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	std::ifstream	ifs1(argv[1]);
	std::ifstream	ifs2("data.csv");
	if (open_files(ifs1, ifs2) == true)
	{
		BitcoinExchange	btcex;
		if (find_stock_data(ifs1, ifs2, btcex) == false)
			return 0;
		ifs1.close();
		ifs2.close();
	}
	else
		std::cerr << "Error: could not open file." << std::endl;
	return 1;
}
