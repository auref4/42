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

bool	check_date(std::string& line, int *i)
{
	while (*i < static_cast<int>(line.size()) && *i < 10)
	{
		if ((*i == 4 || *i == 7) && line[*i] != '-')
			return false;
		else if (isdigit(line[*i] == false))
			return false;
		(*i)++;
	}
	std::string	m = line.substr(5, 2);
	std::string	d = line.substr(8, 2);
	int	month = std::atoi(m.c_str());
	int	day = std::atoi(d.c_str());
	if (month > 12 || day > 31)
		return false;
	return true;
}

bool	check_float(std::string& line, int *i)
{
	int		nb_dot = 0;

	if (*i < static_cast<int>(line.size()) && line[*i] == '-')
		(*i)++;
	if (line[*i] == '.')
		return false;
	while (*i < static_cast<int>(line.size()) && (isdigit(line[*i]) || line[*i] == '.'))
	{
		if (line[*i] == '.')
			nb_dot += 1;
		(*i)++;
	}
	if (nb_dot >= 2 || *i != static_cast<int>(line.size()))
		return false;
	return true;
}

int	check_line(std::string line)
{
	int	i = 0;

	if (check_date(line, &i) == false)
		return BAD_INPUT;
	while (i < static_cast<int>(line.size()) && i < 13)
	{
		if ((i == 10 || i == 12) && line[i] != ' ')
			return BAD_INPUT;
		else if (i == 11 && line[i] != '|')
			return BAD_INPUT;
		i++;
	}
	if (check_float(line, &i) == false)
		return BAD_INPUT;
	std::string	tmp = line.substr(13, line.size() - 13);
	float	nb_btc = std::strtof(tmp.c_str(), 0);
	if (nb_btc < 0)
		return NEGATIVE;
	else if (nb_btc > 1000)
		return TOO_LARGE;
	return NO_ERROR;
}

void	stock_print_data(std::ifstream& ifs1, std::ifstream& ifs2)
{
	BitcoinExchange							btcex;
	std::string								line_ifs1;
	std::string								line_ifs2;
	std::map<std::string, float>::iterator	it;

	while (getline(ifs1, line_ifs1))
	{
		std::string	value = line_ifs1.substr(11, line_ifs1.size() - 11);
		btcex.set_databtc(line_ifs1.substr(0, 10), std::strtof(value.c_str(), 0));
	}
	while (getline(ifs2, line_ifs2))
	{
		btcex.set_nb_error(check_line(line_ifs2));
		if (btcex.get_nb_error() == NO_ERROR)
		{
			btcex.find_good_data(it, line_ifs2);
			btcex.calcul_print(it, line_ifs2);
		}
		else
			btcex.print_error();
	}
}

int	main(int argc, char** argv)
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
		stock_print_data(ifs1, ifs2);
		ifs1.close();
		ifs2.close();
	}
	else
		std::cerr << "Error: could not open file." << std::endl;
	return 1;
}
