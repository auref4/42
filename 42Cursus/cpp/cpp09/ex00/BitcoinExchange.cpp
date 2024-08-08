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
