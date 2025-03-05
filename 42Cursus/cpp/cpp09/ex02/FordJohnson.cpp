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
	int	size_comparison = 2;

	this->recursive_step(size_comparison);
}

void	FordJohnson::recursive_step(int	size_comparison)
{
	std::cout << "size_comparison = " << size_comparison << std::endl;
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it += size_comparison)
	{
		if (std::distance(_deque.begin(), it) + size_comparison > static_cast<int>(_deque.size()))
			break;
		if (*(it + (size_comparison / 2) - 1) > *(it + size_comparison - 1))
			std::swap_ranges(it, it + (size_comparison / 2), it + (size_comparison / 2));
	}
	std::cout << "dequeu sort = ";
	for (std::deque<int>::iterator	it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	if (size_comparison < static_cast<int>(_deque.size()))
		this->recursive_step(size_comparison * 2);
	if (size_comparison <= static_cast<int>(_deque.size()))
		this->binary_search(size_comparison);
}

void	FordJohnson::binary_search(int size_comparison)
{
	std::cout << "size_comparison = " << size_comparison << std::endl;
	std::deque<int>	unsorted;

	for (std::deque<int>::iterator	it = _deque.begin() + size_comparison; it != _deque.end(); it += size_comparison / 2)
	{
		if (std::distance(_deque.begin(), it) + (size_comparison / 2) > static_cast<int>(_deque.size()))
		{
			std::cout << "yo" << std::endl;
			break;
		}
		for (int i = 0; i < (size_comparison / 2); i++)
		{
			unsorted.push_back(*it);
			it = _deque.erase(it);
		}
		if (it != _deque.end())
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
	int	to_insert;
	for (std::deque<int>::iterator it = unsorted.begin(); it != unsorted.end(); it += (size_comparison / 2) + 1)
	{
		std::deque<int>::iterator	link = std::find(_deque.begin(), _deque.end(), *(it + (size_comparison / 2)));
		std::deque<int>::iterator	i_binary = link - 1;
		std::cout << "i_binary distance before / 2 = " << std::distance(_deque.begin(), i_binary) << std::endl;
		i_binary -= (i_binary - _deque.begin()) / 2;
		to_insert = *(it + (size_comparison / 2 - 1));
		std::cout << "i_binary distance after / 2 = " << std::distance(_deque.begin(), i_binary) << std::endl;
		std::cout << "i_binary value =  " << *i_binary << std::endl;
		std::cout << "link = " << *link << std::endl;
		std::cout << "to_insert = " << to_insert << std::endl;

		half_distance = (link - i_binary) / 2;
		half_distance /= size_comparison;
		if (half_distance < 1 || size_comparison == 2)
					half_distance = 1;
		while (1)
		{
			if (i_binary >= link)
			{
				std::cout << "coucou1" << std::endl;
				break;
			}
			if (i_binary != _deque.begin() && to_insert < *(i_binary + (size_comparison / 2 - 1)) && to_insert > *(i_binary - 1))
			{
				std::cout << "coucou2" << std::endl;
				break;
			}
			if (i_binary == _deque.begin() && to_insert < *(i_binary + (size_comparison / 2 - 1)))
			{
				std::cout << "coucou3" << std::endl;
				break;
			}
			if (to_insert > *(i_binary + (size_comparison / 2 - 1)))
			{
				std::cout << "to_insert superieur a i_binary" << std::endl;
				std::cout << "size_comparison = " << size_comparison << std::endl;
				i_binary += (half_distance * (size_comparison / 2));
			}
			else
			{
				std::cout << "to_insert inferieur a i_binary" << std::endl;
				std::cout << "size_comparison = " << size_comparison << std::endl;
				i_binary -= (half_distance * (size_comparison / 2));
			}
			if (half_distance > 1)
				half_distance /= 2;
		}
		int	i = (size_comparison / 2) - 1;
		it += (size_comparison / 2) - 1;
		while (i > 0)
		{
			std::cout << *it << std::endl;
			i_binary = _deque.insert(i_binary, *it);
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

bool	FordJohnson::bool_sort(void)
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
