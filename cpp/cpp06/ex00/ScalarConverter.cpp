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
	int			special = 0;
	std::string	type;
	std::string	special_list[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	while (special < 6 && arg != special_list[special])
		special++;
	if (arg.size() == 1 && (isprint(arg[0]) && !isdigit(arg[0])))
		extractCharAndPrint(arg);
	else if (checkIntDoubleFloat(arg, type) == true || special < 6)
	{
		if (type == "int")
			extractIntAndPrint(arg);
		else if (type == "double" || special < 3)
			extractDoubleAndPrint(arg, special);
		else if (type == "float" || special >= 3)
			extractFloatAndPrint(arg, special);
	}
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
	double	d = std::strtod(arg.c_str(), 0);

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		throw OverflowUnderflow();

	int	nb = static_cast<int>(d);

	if (nb >= 0 && nb < 128 && isprint(nb))
		std::cout << "char : " << "'" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << std::setprecision(1) << std::fixed << static_cast<float>(nb) << 'f' << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << static_cast<double>(nb) << std::endl;
}

void	ScalarConverter::extractDoubleAndPrint(std::string const &arg, int special)
{
	if (special < 6)
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "float : " << arg << 'f' << std::endl;
		std::cout << "double : " << arg << std::endl;
		return ;
	}

	double	d = std::strtod(arg.c_str(), 0);

	if (d == HUGE_VAL || d == -HUGE_VAL || d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
		throw OverflowUnderflow();
	if (d >= 0 && d < 128 && isprint(static_cast<int>(d)))
		std::cout << "char : " << "'" << static_cast<char>(static_cast<int>(d)) << "'" << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << static_cast<int>(d) << std::endl;
	std::cout << "float : " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double : " << d << std::endl;
}

void	ScalarConverter::extractFloatAndPrint(std::string const &arg, int special)
{
	if (special < 6)
	{
		std::string	str = arg.substr(0, arg.size() - 1);

		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "float : " << arg << std::endl;
		std::cout << "double : " << str << std::endl;
		return ;
	}

	float	f = std::strtof(arg.c_str(), 0);

	if (f == HUGE_VALF || f == -HUGE_VALF || f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
		throw OverflowUnderflow();
	if (f >= 0 && f < 128  && isprint(static_cast<int>(f)))
		std::cout << "char : " << "'" << static_cast<char>(static_cast<int>(f)) << "'" << std::endl;
	else
		std::cout << "char : non displayable" << std::endl;
	std::cout << "int : " << static_cast<int>(f) << std::endl;
	std::cout << "float : " << f << 'f' << std::endl;
	std::cout << "double : " << static_cast<double>(f) << std::endl;
}

//EXCEPTION

const char*	ScalarConverter::OverflowUnderflow::what() const throw()
{
	return "!!OVERFLOW/UNDERFLOW DETECTED!!";
}
