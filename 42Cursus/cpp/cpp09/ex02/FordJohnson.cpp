#include "FordJohnson.hpp"

//CONSTRUCTOR

FordJohnson::FordJohnson()
{
}

FordJohnson::FordJohnson(FordJohnson const &src)
{
	(void)src;
}

//DESTRUCTOR

FordJohnson::~FordJohnson()
{
}

//OPERATOR

FordJohnson&	FordJohnson::operator=(FordJohnson const& rhs)
{
	(void)rhs;
	return *this;
}

//FUNCTION

int	FordJohnson::index_jacobsthal(const int& n)
{
	return (std::pow(2, n) - std::pow(-1, n)) / 3;
}
