#include "BitcoinExchange.hpp"

bool	check_line(std::string line)
{
	int	i = 0;
	int	nb_dot = 0;

	while (i < line.size() && i < 14)
	{
		if ((i == 4 || i == 7) && line[i] != '.')
			return false;
		else if ((i == 10 || i == 12) && line[i] != ' ')
			return false;
		else if ((i == 11 && line[i] != '.'))
			return false;
		else if (isdigit(line[i] == false))
			return false;
		i++;
	}
	while (i < line.size() && (isdigit(line[i]) || line[i] == '.'))
	{
		if (line[i] == '.')
			nb_dot += 1;
		i++;
	}
	if (nb_dot >= 2 || i != line.size())
		return false;
	return true;
}

void	stock_print_data(std::ifstream& ifs1, std::ifstream& ifs2)
{
	BitcoinExchange	btcex;
	std::string		line_ifs1;
	std::string		line_ifs2;

	while (getline(ifs1, line_ifs1))
	{
		if (check_line(line_ifs1) == false)
			btcex.set_nb_error(1);
		else
		{
			btcex.set_databtc(line_ifs1.substr(0, 10), std::stof(line_ifs1.substr(13, line_ifs1.size() - 13)))
			while(getline(ifs2, line_ifs2))
			{

			}
		}

	}
}

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
		stock_print_data(ifs1, ifs2)
		ifs1.close();
		ifs2.close();
	}
	else
		std::cerr << "Error: could not open file." << std::endl;
	return 1;
}
