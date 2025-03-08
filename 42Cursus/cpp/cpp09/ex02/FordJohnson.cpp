#include "FordJohnson.hpp"

//CONSTRUCTOR

FordJohnson::FordJohnson()
{
}

FordJohnson::FordJohnson(FordJohnson const &src) : _deque(src._deque), _vector(src._vector)
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
	if (this->check_duplicates() == true)
		throw ThrowException("invalid inputs, duplicates are not accepted !");
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

bool	FordJohnson::check_duplicates(void)
{
	int	i = 0;

	while (i < static_cast<int>(_deque.size() - 1))
	{
		int				nb = *(_deque.begin() + i);
		std::deque<int>::iterator	it = _deque.begin() + i + 1;
		while (it < _deque.end())
		{
			if (nb == *it)
				return true;
			it++;
		}
		i++;
	}
	return false;
}

void	FordJohnson::manage(void)
{
	this->recursive_step(2);
}

void	FordJohnson::recursive_step(int	size_comparison)
{
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it += size_comparison)
	{
		if (std::distance(_deque.begin(), it) + size_comparison > static_cast<int>(_deque.size()))
			break;
		if (*(it + (size_comparison / 2) - 1) > *(it + size_comparison - 1))
			std::swap_ranges(it, it + (size_comparison / 2), it + (size_comparison / 2));
	}
	if (size_comparison < static_cast<int>(_deque.size()))
		this->recursive_step(size_comparison * 2);
	if (size_comparison <= static_cast<int>(_deque.size()))
	{
		std::deque<int>	unsorted;

		this->sort_odd(unsorted, size_comparison);
		this->binary_search(unsorted, size_comparison);
	}
}

void	FordJohnson::sort_odd(std::deque<int>& unsorted, int size_comparison)
{
	for (std::deque<int>::iterator	it = _deque.begin() + size_comparison; it != _deque.end(); it += size_comparison / 2)
	{
		if (std::distance(_deque.begin(), it) + (size_comparison / 2) > static_cast<int>(_deque.size()))
			break;
		for (int i = 0; i < (size_comparison / 2); i++)
		{
			unsorted.push_back(*it);
			it = _deque.erase(it);
		}
		if (it != _deque.end())
			unsorted.push_back(*it);
	}
}

void	FordJohnson::binary_search(std::deque<int>& unsorted, int size_comparison)
{
	int	to_insert;
	int 	half_distance;

	for (std::deque<int>::iterator it = unsorted.begin(); it != unsorted.end(); it += (size_comparison / 2) + 1)
	{
		std::deque<int>::iterator	link = std::find(_deque.begin(), _deque.end(), *(it + (size_comparison / 2)));
		std::deque<int>::iterator	i_binary = link - 1 - (link - 1 - _deque.begin()) / 2;

		to_insert = *(it + (size_comparison / 2 - 1));
		half_distance = (link - i_binary) / 2 / size_comparison;
		if (half_distance < 1 || size_comparison == 2)
			half_distance = 1;
		while (1)
		{
			if (i_binary >= link)
				break;
			if (i_binary != _deque.begin() && to_insert < *(i_binary + (size_comparison / 2 - 1)) && to_insert > *(i_binary - 1))
				break;
			if (i_binary == _deque.begin() && to_insert < *(i_binary + (size_comparison / 2 - 1)))
				break;
			if (to_insert > *(i_binary + (size_comparison / 2 - 1)))
				i_binary += (half_distance * (size_comparison / 2));
			else
				i_binary -= (half_distance * (size_comparison / 2));
			if (half_distance > 1)
				half_distance /= 2;
		}
		it += (size_comparison / 2) - 1;
		for (int i = (size_comparison / 2) - 1; i > 0; i--)
		{
			i_binary = _deque.insert(i_binary, *it);
			it--;	
		}		
		_deque.insert(i_binary, *it);
		if (std::distance(unsorted.begin(), it) + (size_comparison / 2) + 1 > static_cast<int>(unsorted.size()))
			break;
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

bool	FordJohnson::check_sort(void)
{
	int	i = 0;

	while (i < static_cast<int>(_deque.size()))
	{
		std::deque<int>::iterator it = _deque.begin() + i;
		while (it < _deque.end() - 1)
		{
			if (*it > *(it + 1))
			{
				std::cout << "it = " << *it << ", it+1 = " << *(it + 1) << std::endl;
				return false;
			}
			it++;
		}
		i++;
	}
	return true;
}
