#include "FordJohnson.hpp"

//CONSTRUCTOR

FordJohnson::FordJohnson() : _pair_odd(0)
{
}

FordJohnson::FordJohnson(FordJohnson const &src) : _deque(src._deque), _vector(src._vector), _pair_odd(src._pair_odd)
{
}

FordJohnson::FordJohnson(char** argv)
{
	double	d;
	char*	endptr;

	for (int i = 1; argv[i]; i++)
	{
		d = strtod(argv[i], &endptr);
		if (*endptr != '\0' || d < 0)
			throw ThrowException("invalid inputs, arguments should be numbers between 0 and INT_MAX");
		if (d > INT_MAX)
			throw ThrowException("overflow detected !");
		_deque.push_back(static_cast<int>(d));
		_vector.push_back(static_cast<int>(d));
	}
	if (_deque.size() % 2 == 0)
		_pair_odd = 0;
	else
		_pair_odd = 1;
}

//DESTRUCTOR

FordJohnson::~FordJohnson()
{
}

//OPERATOR

FordJohnson&	FordJohnson::operator=(FordJohnson const& rhs)
{
	if (this != &rhs)
	{
		this->_deque = rhs._deque;
		this->_vector = rhs._vector;
		this->_pair_odd = rhs._pair_odd;
	}
	return *this;
}

//FUNCTIONS

void	FordJohnson::sort(void)
{
	int	size_comparaison = 2;

	this->recursive_step(size_comparaison);
}

void	FordJohnson::recursive_step(int	size_comparaison)
{
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end() - _pair_odd; it += size_comparaison)
	{
		if (*(it + (size_comparaison / 2) - 1) > *(it + size_comparaison - 1))
			std::swap_ranges(it, it + (size_comparaison / 2), it + (size_comparaison / 2));
	}
	std::cout << "dequeu sort = ";
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	if (size_comparaison < static_cast<int>(_deque.size()))
		this->recursive_step(size_comparaison * 2);
	if (size_comparaison <= static_cast<int>(_deque.size() - _pair_odd) / 2)
		this->binary_search(size_comparaison);
}

void	FordJohnson::binary_search(int size_comparaison)
{
	std::deque<int>	unsorted;


}

void	FordJohnson::print_container(void)
{
	std::cout << "dequeu = ";
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "vector = ";
	for (std::vector<int>::iterator	it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
