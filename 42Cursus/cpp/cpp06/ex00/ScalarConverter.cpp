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

void	ScalarConverter::convert(std::string const &arg)
{
	std::string	type;
	std::string	special_list[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	for (int i = 0; i < 6 && arg != special_list[i]; i++);
	if (arg.size() == 1 && (isprint(arg[0]) && !isdigit(arg[0])))
		extractCharAndPrint(arg);
	else if (checkIntDoubleFloat(arg, type) == true || i < 6)
	{
		if (type == "int")
			extractIntAndPrint(arg);
		else if (type == "double" || i < 3)
			extractDoubleAndPrint(arg, i);
		else if (type == "float" || i <= 3)
			extractFloatAndPrint(arg, i);
	}
	else if (arg == "nan" || arg == "nanf" || arg == "-inf" || arg == "+inf" || arg == "-inff" || arg == "+inff")
		specialPrint(arg);
	else
		std::cout << "Incorrect argument" << std::endl;
}

bool	ScalarConverter::checkIntDoubleFloat(std::string const &arg, std::string &type)
{
	int	i = 0;

	if (isdigit(arg[0]) || arg[0] == '-' || arg[0] == '+')
	{
		if (arg[0] == '-' || arg[0] == '+')
			i++;
		while (i < static_cast<int>(arg.size()) && isdigit(arg[i]))
			i++;
		if (i == static_cast<int>(arg.size()))
		{
			type = "int";
			return true;
		}
		else if (arg[i] == '.' && i + 1 < static_cast<int>(arg.size()))
		{
			i++;
			while (i < static_cast<int>(arg.size()) && isdigit(arg[i]))
				i++;
			if (i == static_cast<int>(arg.size()))
			{
				type = "double";
				return true;
			}
			else if (i + 1 == static_cast<int>(arg.size()) && arg[i] == 'f')
			{
				type = "float";
				return true;
			}
		}
	}
	return false;
}

void	ScalarConverter::extractCharAndPrint(std::string const &arg)
{
	char	c =	arg[0];

	std::cout << "char : " << "'" << c << "'" << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << std::setprecision(1) << std::fixed << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::extractIntAndPrint(std::string const &arg)
{
	int	nb = std::atoi(arg.c_str());

	if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
				throw OverflowUnderflow();
	if (isprint(nb))
		std::cout << "char : " << "'" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << std::setprecision(1) << std::fixed << static_cast<float>(nb) << 'f' << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << static_cast<double>(nb) << std::endl;
}

void	ScalarConverter::extractDoubleAndPrint(std::string const &arg, int i)
{
	double	d = std::atof(arg.c_str());

	if (isprint(static_cast<int>(d)))
		std::cout << "char : " << "'" << static_cast<char>(static_cast<int>(d)) << "'" << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << static_cast<int>(d) << std::endl;
	std::cout << "float : " << std::setprecision(1) << std::fixed << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << d << std::endl;
}

void	ScalarConverter::extractFloatAndPrint(std::string const &, int i)
{
	std::string	str;

	str = arg.substr(0, arg.size() - 1);
	float	f = std::atof(str.c_str());

	if (isprint(static_cast<int>(f)))
		std::cout << "char : " << "'" << static_cast<char>(static_cast<int>(f)) << "'" << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << static_cast<int>(f) << std::endl;
	std::cout << "float : " << std::setprecision(1) << std::fixed << f << 'f' << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << static_cast<double>(f) << std::endl;
}

//EXCEPTION

const char*	ScalarConverter::OverflowUnderflow::what() const throw()
{
	return "Overflow or Underflow detected";
}
