#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class	Span
{
	public :

	Span();									//CANONICAL
	Span(unsigned int n);
	Span(Span const &src);					//CANONICAL
	~Span();								//CANONICAL

	Span&	operator=(Span const &rhs);		//CANONICAL

	void	addNumber(int nb);
	void	addMultipleNumbers(unsigned int range);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	class	FullElements : public std::exception
	{
		public :

		virtual const char*	what() const throw();
	};
	class	VoidElements : public std::exception
	{
		public :

		virtual const char*	what() const throw();
	};

	private :

	std::vector<int>	m_vec;
	unsigned int		m_n;
};

#endif
