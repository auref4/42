#include "BitcoinExchange.hpp"

bool	check_line(std::string line)
{
	int	i = 0;
	int	nb_dot = 0;

	while (i < line.size() && i < 10)
	{
		if ((i == 4 || i == 7) && line[i] != '.')
			return false;
		else if (isdigit(line[i] == false))
			return false;
		i++;
	}
	if (i + 2 > line.size() || line[i] != ' ' || line[i + 1] != '.' || line[i + 2] != ' ')
		return false;
	i += 3;
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
	std::string		date;
	int				nb_btc;

	while (getline(ifs1, line_ifs1))
		btcex.set_databtc(line_ifs1.substr(0, 9), std::stof(line_ifs1.substr(11, line_ifs1.size() - 11)));
	while (getline(ifs2, line_ifs2))
	{
		if (check_line(line_ifs2) == false)
			set_nb_error(1);
		else
		{
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
	std::ifstream	ifs1("data.csv");
	std::ifstream	ifs2(argv[1]);
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
