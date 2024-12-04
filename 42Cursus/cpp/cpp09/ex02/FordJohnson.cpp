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
	int	size_comparison = 2;

	this->recursive_step(size_comparison);
}

void	FordJohnson::recursive_step(int	size_comparison)
{
	std::cout << "size_comparison = " << size_comparison << std::endl;
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end() - _pair_odd; it += size_comparison)
	{
		if (*(it + (size_comparison / 2) - 1) > *(it + size_comparison - 1))
			std::swap_ranges(it, it + (size_comparison / 2), it + (size_comparison / 2));
	}
	std::cout << "dequeu sort = ";
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	if (size_comparison < static_cast<int>(_deque.size()))
		this->recursive_step(size_comparison * 2);
	if (size_comparison <= static_cast<int>(_deque.size() - _pair_odd) / 2)
		this->binary_search(size_comparison);
}

void	FordJohnson::binary_search(int size_comparison)
{
	std::cout << "size_comparison = " << size_comparison << std::endl;
	std::deque<int>	unsorted;

	for (std::deque<int>::iterator	it = _deque.begin() + size_comparison; it != _deque.end() - _pair_odd; it += size_comparison / 2)
	{
		for (int i = 0; i < (size_comparison / 2); i++)
		{
			unsorted.push_back(*it);
			_deque.erase(it);
		}
		if (it < _deque.end())
			unsorted.push_back(*it);
	}

	std::cout << "sorted list = ";
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "unsorted list = ";
	for (std::deque<int>::iterator	it = unsorted.begin(); it != unsorted.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	int half_distance;
	for (std::deque<int>::iterator it = unsorted.begin(); it != unsorted.end(); it += (size_comparison / 2) + 1)
	{
		std::deque<int>::iterator	link = std::find(_deque.begin(), _deque.end(), *(it + (size_comparison / 2) + 1));
		std::deque<int>::iterator	i_binary = link;
		i_binary -= (i_binary - _deque.begin()) / 2;
		if (*(it + 1) > *i_binary)
		{
			while (*(it + 1) > *i_binary)
			{
				std::cout << *i_binary << std::endl;
				if (*i_binary == *link)
				{
					//i_binary -= 1;
					break;
				}
				half_distance = (link - i_binary) / 2;
				std::cout << half_distance << std::endl;
				if (half_distance == 0)
					break;
				i_binary += half_distance;
			}
		}
		else
		{
			while (*(it + 1) < *i_binary)
			{
				half_distance = (i_binary - _deque.begin()) / 2;
				if (half_distance == 0)
					break;
				i_binary -= half_distance;
			}
		}
		int	i = (size_comparison / 2) - 1;
		it += (size_comparison / 2) - 1;
		while (i > 0)
		{
			_deque.insert(i_binary, *it);
			it--;
			i--;
		}
		_deque.insert(i_binary, *it);
		//for (std::deque<int>::iterator tmp = it + (size_comparison / 2) - 1; tmp != tmp - (size_comparison / 2) + 1; tmp--)
		//	_deque.insert(i_binary, *tmp);

		std::cout << "sorted list = ";
		for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "unsorted list = ";
		for (std::deque<int>::iterator	it = unsorted.begin(); it != unsorted.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;
	}
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
