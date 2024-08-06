#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class	BitcoinExchange
{
	public :

	BitcoinExhange();										//CANONICAL
	BitcoinExhange(BitcoinExhange const &src);				//CANONICAL
	~BitcoinExhange();										//CANONICAL
	BitcoinExhange&	operator=(BitcoinExhange const &rhs);	//CANONICAL

	private :

	std::map<std::string, float>	databtc;
};

#endif
