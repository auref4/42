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
	_nb_error = nb;
}

void	BitcoinExchange::set_databtc(std::string str, float f)
{
	_databtc.insert(std::pair<std::string, float>(str, f));
}

void	BitcoinExchange::find_good_data(std::map<std::string, float>::iterator& it, std::string& line)
{
	std::string	date = line.substr(0, 10);

	if (strcmp(date.c_str(), "2009-01-02") < 0 && _nb_error == NO_ERROR)
		_nb_error = PAST_DATE;
	else if (strcmp(date.c_str(), "2022-03-29") > 0 && _nb_error == NO_ERROR)
		_nb_error = FUTURE_DATE;
	else if (this->_nb_error == NO_ERROR)
	{
		it = _databtc.lower_bound(date);
		if (it->first == date)
			return ;
		else if (it == _databtc.begin())
			it++;
		else
			it--;
	}
}

void	BitcoinExchange::calcul_print(std::map<std::string, float>::iterator& it, std::string& line)
{
	switch(_nb_error)
	{
		case BAD_INPUT :
			std::cerr << "Error: bad input => " << line << std::endl;
			break;
		case NEGATIVE :
			std::cerr << "Error: not a positive number." << std::endl;
			break;
		case TOO_LARGE :
			std::cerr << "Error: too large number." << std::endl;
			break;
		case PAST_DATE :
			std::cerr << "Error : bitcoin didn't exist before 2009-01-02." << std::endl;
			break;
		case FUTURE_DATE :
			std::cerr << "Error : impossible to predict the price of bicoin after 2022-03-29." << std::endl;
			break;
		case NO_ERROR :
			std::string date = line.substr(0, 10);
			std::string	tmp = line.substr(13, line.size() - 13);
			float		value = it->second;
			float		nb_btc = strtof(tmp.c_str(), 0);
			float		result = nb_btc * value;
			std::cout << date <<" => " << nb_btc << " = " << result << std::endl;
	}
}
