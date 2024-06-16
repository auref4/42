#ifndef	EASYFIND_HPP
#define	EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

class	NoOccurence : public std::exception
{
	public :

	virtual const char *	what() const throw();
};

template <typename T>
typename T::iterator	easyfind(T &container, int nb);

#include "easyfind.tpp"

#endif
