#include "BitcoinExchange.hpp"

//CONSTRUCTOR

BitcoinExchange::BitcoinExchange() : _nb_error(0)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) : _databtc(src._databtc), _nb_error(src._nb_error)
{
}

//DESTRUCTOR

BitcoinExchange::~BitcoinExchange()
{
}

//OPERATOR

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	std::cout << "BitcoinExchange copy operator called" << std::endl;

	if (this!= &rhs)
	{
		this->_databtc = rhs._databtc;
		this->_nb_error = rhs._nb_error;
	}
	return *this;
}

//FUNCTIONS

void	BitcoinExchange::set_nb_error(int nb)
{
	this->_nb_error = nb;
}

int	BitcoinExchange::get_nb_error(void) const
{
	return this->_nb_error;
}

void	BitcoinExchange::set_databtc(std::string str, float f)
{
	this->_databtc.insert(std::pair<std::string, float>(str, f));
}

void	BitcoinExchange::find_good_data(std::map<std::string, float>::iterator& it, std::string& line)
{
	std::string	date = line.substr(0, 10);

	it = this->_databtc.lower_bound(date);
	if (it->first == date)
		return ;
	else if (it == this->_databtc.begin())
		it++;
	else
		it--;
}

void	BitcoinExchange::calcul_print(std::map<std::string, float>::iterator& it, std::string& line)
{
	std::string date = line.substr(0, 10);
	float		value = it->second;
	std::string	tmp = line.substr(13, line.size() - 13);
	float		nb_btc = strtof(tmp.c_str(), 0);
	float		result = nb_btc * value;

	std::cout << date <<" => " << nb_btc << " = " << result << std::endl;
}

void	BitcoinExchange::print_error(std::string& line) const
{
	if (this->_nb_error == BAD_INPUT)
		std::cerr << "Error: bad input => " << line << std::endl;
	if (this->_nb_error == NEGATIVE)
		std::cerr << "Error: not a positive number." << std::endl;
	if (this->_nb_error == TOO_LARGE)
		std::cerr << "Error: too large number." << std::endl;
}
