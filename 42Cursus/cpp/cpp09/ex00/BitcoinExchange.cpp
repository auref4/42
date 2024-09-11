#include "BitcoinExchange.hpp"

//CONSTRUCTOR

BitcoinExchange::BitcoinExchange() : _nb_error(0)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const src) : _databtc(src.databtc), _nb_error(src.nb_error)
{
	std::cout << "BitcoinExchange copy constuctor called" << std::endl;
}

//DESTRUCTOR

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange default destructor called" << std::endl;
}

//OPERATOR

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &rhs)
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

void	BitcoinExchange::find_good_data(std::map<std::string, float>::iteator& it, std::string& line)
{
	std::string	date = line.substr(0, 9);

	it = this->_databtc.find(date);
	if (it != this->_databtc.end())
		it = std::lower_bound(this->_databtc.begin(), this->_databtc.end(), date);
}

void	BitcoinExchange::calcul_print(std::map<std::string, float>::iterator& it)
{
	std::string date = it->first;
	float		value = it->second;


}

void	BitcoinExchange::print_error()
{
	if (this->_nb_error == BAD_INPUT)
		std::cerr << "Error: bad input." << std::endl;
	if (this->_nb_error == NEGATIVE)
		std::cerr << "Error: not a positive number." << std::endl;
	if (this->_nb_error == TOO_LARGE)
		std::cerr << "Error: too large number." << std::endl;
}
