#include "BitcoinExchange.hpp"

//CONSTRUCTOR

BitcoinExchange::BitcoinExchange() : nb_error(0)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const src) : databtc(src.databtc), nb_error(src.nb_error)
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
		this->databtc = rhs.databtc;
		this->nb_error = rhs.nb_error;
	}
	return *this;
}

//FUNCTIONS

void	BitcoinExchange::set_nb_error(int nb)
{
	this->nb_error = nb;
}

int	BitcoinExchange::get_nb_error(void) const
{
	return this->nb_error;
}
