#include "ScalarConverter.hpp"

//CONSTRUCTOR

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

//DESTRUCTOR

ScalarConverter::~ScalarConverter()
{
}

//OPERATOR

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void) rhs;
	return *this;
}

//MEMBER FUNCTION

void	ScalarConverter::convert(std::string const &param)
{
	std::string	type;

	if (checkChar(param, type) == true)
	{
		char	c = extractChar(param);
		printConversion(c);
	}
	else if (checkIntDoubleFloat(param, type) == true)
	{
		if (type == "int")
		{
			int	nb = extractInt(param);
			printConversion(nb);
		}
		else if (type == "double")
		{
			double	d = extractDouble(param);
			printConversion(d);
		}
		else if (type == "float")
		{
			float	f = extractFloat(param);
			printConversion(f);
		}
	}

}

bool	ScalarConverter::checkChar(std::string const &param, std::string &type)
{
	if (param.size() == 3 && param[0] == 39 && param[2] == 39 && (islower(param[1]) || isupper(param[1])))
	{
		type = "char";
		return true;
	}
	return false;
}

bool	ScalarConverter::checkIntDoubleFloat(std::string const &param, std::string &type)
{
	int	i = 0;

	if (isdigit(param[0]) || param[0] == '-' || param[0] == '+')
	{
		if (param[0] == '-' || param[0] == '+')
			i++;
		while (i < static_cast<int>(param.size()) && isdigit(param[i]))
			i++;
		if (i == static_cast<int>(param.size()))
		{
			type = "int";
			return true;
		}
		else if (param[i] == '.')
		{
			i++;
			while (i < static_cast<int>(param.size()) && isdigit(param[i]))
				i++;
			if (i == static_cast<int>(param.size()))
			{
				type = "double";
				return true;
			}
			else if ((i + 1) == static_cast<int>(param.size()) && param[i] == 'f')
			{
				type = "float";
				return true;
			}
		}
	}
	return false;
}

char	ScalarConverter::extractChar(std::string const &param)
{
	char	c =	param[1];

	return c;
}

int	ScalarConverter::extractInt(std::string const &param)
{
	int	nb = std::atoi(param.c_str());

	return nb;
}

double	ScalarConverter::extractDouble(std::string const &param)
{
	double	d = std::atof(param.c_str());

	return d;
}

float	ScalarConverter::extractFloat(std::string const &param)
{
	std::string	str;

	str = param.substr(0, param.size() - 1);
	float	f = std::atof(str.c_str());

	return f;
}

void	ScalarConverter::printConversion(char c)
{
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::printConversion(int nb)
{
	if (isprint(nb))
		std::cout << "char : " << static_cast<char>(nb) << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << static_cast<float>(nb) << 'f' << std::endl;
	std::cout << "double : " << static_cast<double>(nb) << std::endl;
}

void	ScalarConverter::printConversion(float f)
{
	if (isprint(static_cast<int>(f)))
		std::cout << "char : " << static_cast<char>(static_cast<int>(f)) << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << static_cast<int>(f) << std::endl;
	std::cout << "float : " << f << 'f' << std::endl;
	std::cout << "double : " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::printConversion(double d)
{
	if (isprint(static_cast<int>(d)))
		std::cout << "char : " << static_cast<char>(static_cast<int>(d)) << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << static_cast<int>(d) << std::endl;
	std::cout << "float : " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double : " << d << std::endl;
}
