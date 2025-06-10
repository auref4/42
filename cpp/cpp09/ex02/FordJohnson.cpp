#include "FordJohnson.hpp"

//CONSTRUCTOR

FordJohnson::FordJohnson() : _comparisons(0)
{
}

FordJohnson::FordJohnson(FordJohnson const &src) : _comparisons(src._comparisons)
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
	if (this != &rhs)
		this->_comparisons = rhs._comparisons;
	return *this;
}

//FUNCTION

int	FordJohnson::get_comparisons(void)
{
	return this->_comparisons;
}

int	FordJohnson::index_jacobsthal(const int& n)
{
	return (std::pow(2, n) - std::pow(-1, n)) / 3;
}
