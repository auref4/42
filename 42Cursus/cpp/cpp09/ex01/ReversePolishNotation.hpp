#ifndef	REVERSEPOLISHNOTATION_HPP
#define	REVERSEPOLISHNOTATION_HPP

#include <iostream>
#include <stack>
#include <list>
#include <cstring>
#include <cctype>
#include <cstdlib>

class	ReversePolishNotation
{
	public :

	ReversePolishNotation();												//CANONICAL
	ReversePolishNotation(ReversePolishNotation const& src);				//CANONICAL
	~ReversePolishNotation();												//CANONICAL

	ReversePolishNotation&	operator=(ReversePolishNotation const& rhs);	//CANONICAL

	bool	calculate(std::string argument);
	void	print_result(void) const;

	private :

	std::stack<float, std::list<float> >	_stack_rpn;

	void	manage_stack(int symbol);
};

bool	issymbol(int nb);

#endif
