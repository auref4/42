#ifndef FORDJOHNSON_HPP
#define FORDJOHNSON_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <climits>
#include <algorithm>
#include <iterator>
#include <deque>
#include <vector>

class	FordJohnson
{
	public :

	FordJohnson();											//CANONICAL
	FordJohnson(FordJohnson const& src);					//CANONICAL
	FordJohnson(char** argv);
	~FordJohnson();											//CANONICAL

	FordJohnson&	operator=(FordJohnson const& rhs);		//CANONICAL

	void	print_container();
	void	recursive_sort(int size_comparaison);
	bool	check_duplicates(void);
	bool	check_sort(void);

	class	ThrowException : public std::exception
	{
		public :

		explicit ThrowException(const std::string& message) : _error_message(message){}
		virtual ~ThrowException() throw() {}

		const char*	what() const throw()
		{
			return _error_message.c_str();
		}

		private :

		std::string	_error_message;
	};

	private :

	void				sort_odd(int size_comparison);
	void				push_unsorted(std::deque<int>& unsorted, int size_comparison);
	void				insert_sorted(std::deque<int>& unsorted, int size_comparaison);
	std::deque<int>::iterator	binary_search(std::deque<int>::iterator& it, int size_comparaison);

	std::deque<int>		_deque;
	std::vector<int>	_vector;
};

#endif
