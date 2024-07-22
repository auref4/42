#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <iostream>
#include <exception>

class	Span
{
	public :

	Span();									//CANONICAL
	Span(unsigned int n);
	Span(Span const &src);					//CANONICAL
	~Span();								//CANONICAL

	Span&	operator=(Span const &rhs);		//CANONICAL

	void	addNumber(int nb);
	void	addMultipleNumbers();
	int		shortestSpan(void) const;
	int		largestSpan(void) const;

	class	FullElements : public std::exception
	{
		public :

		virtual const char*	what() const throw();
	}
	class	VoidElements : public std::exception
	{
		public :

		virtual const char*	what() const throw();
	}

	private :

	unsigned int	*elements;
	unsigned int	index_elements;
	unsigned int	nb_elements;
};

#endif
