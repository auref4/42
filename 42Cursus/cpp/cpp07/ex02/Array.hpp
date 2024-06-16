#ifndef	ARRAY_HPP
#define	ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class	Array
{
	public :

	Array();									//CANONICAL
	Array(unsigned int n);
	Array(Array<T> const &src);					//CANONICAL
	~Array();									//CANONICAL

	Array&	operator=(Array<T> const &rhs);		//CANONICAL
	T&		operator[](unsigned int index);

	unsigned int	size() const;

	class	IncorrectIndex : public std::exception
	{
		public :

		virtual const char *	what() const throw();
	};

	private :

	T				*elements;
	unsigned int	nb_elements;
};

#include "Array.tpp"

#endif
