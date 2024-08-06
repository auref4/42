#include "BitcoinExchange.hpp"

//CONSTRUCTOR

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const src)
{
	std::cout << "BitcoinExchange copy constuctor called" << std::endl;

	this->databtc = src.databtc;
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
		this->databtc = rhs.databtc;
	return *this;
}

//FUNCTIONS
