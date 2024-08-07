#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#define	BAD_INPUT 1
#define	NEGATIVE 2
#define	INT_MAX 3

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
	void	set_nb_error(int nb);
	int		get_nb_error(void) const;
	void	set_databtc(std::string str, float f);

	private :

	std::map<std::string, float>	databtc;
	int								nb_error;
};

#endif
