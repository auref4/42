#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iomanip>

class	ScalarConverter
{
	public :

	static void	convert(std::string const &arg);

	private :

	ScalarConverter();												//CANONICAL
	ScalarConverter(ScalarConverter const &src);					//CANONICAL
	~ScalarConverter();												//CANONICAL

	ScalarConverter&	operator=(ScalarConverter const &rhs);		//CANONICAL

	static bool	checkIntDoubleFloat(std::string const &arg, std::string &type);
	static void	extractCharAndPrint(std::string const &arg);
	static void	extractIntAndPrint(std::string const &arg);
	static void	extractDoubleAndPrint(std::string const &arg, int i);
	static void	extractFloatAndPrint(std::string const &arg, int i);

	class	OverflowUnderflow : public std::exception
	{
		public :

		virtual const char*	what() const throw();
	};
};

#endif
