#ifndef	REVERSEPOLISHNOTATION_HPP
#define	REVERSEPOLISHNOTATION_HPP

#include <iostream>
#include <stack>
#include <list>
#include <cstring>
#include <cctype>
#include <cstdlib>

#define NO_ERROR 0
#define	INCORRECT_RPN 1
#define	DIVISION_ZERO 2


class	ReversePolishNotation
{
	public :

	ReversePolishNotation();												//CANONICAL
	ReversePolishNotation(ReversePolishNotation const& src);				//CANONICAL
	~ReversePolishNotation();												//CANONICAL

	ReversePolishNotation&	operator=(ReversePolishNotation const& rhs);	//CANONICAL

	int		calculate(std::string argument);
	void	print_result(void) const;

	private :

	std::stack<float, std::list<float> >	_stack_rpn;

	bool	manage_stack(int symbol);
};

bool	issymbol(int nb);

#endif
