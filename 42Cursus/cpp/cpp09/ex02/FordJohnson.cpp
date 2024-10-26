#include "FordJohnson.hpp"

//CONSTRUCTOR

FordJohnson::FordJohnson() : _to_last_element(0), _size_comparaison(0), _power_of_two(0), _pair_odd(0)
{
}

FordJohnson::FordJohnson(FordJohnson const &src) : _deque(src._deque), _vector(src._vector), _to_last_element(src._to_last_element),
_size_comparaison(src._size_comparaison), _power_of_two(src._power_of_two), _pair_odd(src._pair_odd)
{
}

FordJohnson::FordJohnson(char** argv) : _to_last_element(0), _size_comparaison(1), _power_of_two(2)
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
	}
	return *this;
}

//FUNCTIONS

void	FordJohnson::sort(void)
{
	for (std::deque<int>::iterator	it = _deque.begin(); it < _deque.end() - _pair_odd; it += _power_of_two)
	{
		if (_power_of_two * 2 > static_cast<int>(_deque.size()))
			break ;
		std::deque<int>::iterator	nb1 = it + _to_last_element;
		std::deque<int>::iterator	nb2 = it + _size_comparaison + _to_last_element;
		if (*nb1 > *nb2)
			std::swap_ranges(_deque.begin(), _deque.begin() + _size_comparaison, _deque.begin() + _size_comparaison);
	}
	if (_power_of_two * 2 < static_cast<int>(_deque.size()))
	{
		increment_variable();
		sort();
	}
	decrement_variable();
}

void	FordJohnson::increment_variable(void)
{
	if (_to_last_element == 0)
		_to_last_element += 1;
	else
		_to_last_element *= 2;
	_size_comparaison *= 2;
	_power_of_two *= 2;
}

void	FordJohnson::decrement_variable(void)
{
	if (_to_last_element == 1)
		_to_last_element -= 1;
	else
		_to_last_element /= 2;
	_size_comparaison /= 2;
	_power_of_two /= 2;
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

