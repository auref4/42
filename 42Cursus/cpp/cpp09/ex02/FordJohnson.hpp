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

	void	sort(void);
	void	print_container(void);

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

	void	recursive_step(int	size_comparaison);
	void	binary_search(int size_comparaison);

	std::deque<int>		_deque;
	std::vector<int>	_vector;
	int					_pair_odd;
};

#endif
