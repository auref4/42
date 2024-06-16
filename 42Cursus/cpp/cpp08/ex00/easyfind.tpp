#ifndef	EASYFIND_TPP
#define	EASYFIND_TPP

#include "easyfind.hpp"

const char *	NoOccurence::what() const throw()
{
	return "No occurence find";
}

template <typename T>
typename T::iterator	easyfind(T &container, int nb)
{
	typename T::iterator	i = std::find(container.begin(), container.end(), nb);
	if (i != container.end())
		return i;
	throw NoOccurence();
}

#endif
