#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#define	NO_ERROR 0
#define	BAD_INPUT 1
#define	NEGATIVE 2
#define	TOO_LARGE 3

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <map>

class	BitcoinExchange
{
	public :

	BitcoinExchange();											//CANONICAL
	BitcoinExchange(BitcoinExchange const& src);				//CANONICAL
	~BitcoinExchange();											//CANONICAL
	BitcoinExchange&	operator=(BitcoinExchange const& rhs);	//CANONICAL
	void	set_nb_error(int nb);
	int		get_nb_error(void) const;
	void	set_databtc(std::string str, float f);
	void	find_good_data(std::map<std::string, float>::iterator& it, std::string& line);
	void	calcul_print(std::map<std::string, float>::iterator& it, std::string& line);
	void	print_error() const;

	private :

	std::map<std::string, float>	_databtc;
	int								_nb_error;
};

#endif
