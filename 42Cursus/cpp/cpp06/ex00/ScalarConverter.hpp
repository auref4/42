#ifndef	SCALARCONVERTER_HPP
#define	SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class	ScalarConverter
{
	public :

	static void	convert(std::string const &param);

	private :

	ScalarConverter();												//CANONICAL
	ScalarConverter(ScalarConverter const &src);					//CANONICAL
	~ScalarConverter();												//CANONICAL

	ScalarConverter&	operator=(ScalarConverter const &rhs);		//CANONICAL

	static bool		checkChar(std::string const &param, std::string &type);
	static bool		checkIntDoubleFloat(std::string const &param, std::string &type);
	static char		extractChar(std::string const &param);
	static int		extractInt(std::string const &param);
	static double	extractDouble(std::string const &param);
	static float	extractFloat(std::string const &param);
	static void		printConversion(char c);
	static void		printConversion(int nb);
	static void		printConversion(double d);
	static void		printConversion(float f);
};

#endif
