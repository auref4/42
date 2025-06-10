#include "ReversePolishNotation.hpp"

//CONSTRUCTOR

ReversePolishNotation::ReversePolishNotation()
{
}

ReversePolishNotation::ReversePolishNotation(ReversePolishNotation const& src) : _stack_rpn(src._stack_rpn)
{
}

//DESTRUCTOR

ReversePolishNotation::~ReversePolishNotation()
{
}

//OPERATOR

ReversePolishNotation&	ReversePolishNotation::operator=(ReversePolishNotation const& rhs)
{
	if (this != &rhs)
		this->_stack_rpn = rhs._stack_rpn;
	return *this;
}

//FUNCTIONS

int	ReversePolishNotation::calculate(std::string argument)
{
	for (int i = 0; i < static_cast<int>(argument.size()); i++)
	{
		if (isdigit(argument[i]) == true)
		{
			float	f = static_cast<float>(argument[i]) - 48;
			_stack_rpn.push(f);
		}
		if (issymbol(argument[i]) == true)
		{
			if (_stack_rpn.size() < 2)
				return INCORRECT_RPN;
			if (this->manage_stack(argument[i]) == false)
				return DIVISION_ZERO;
		}
	}
	if (this->_stack_rpn.size() > 1)
		return INCORRECT_RPN;
	return NO_ERROR;
}

bool	ReversePolishNotation::manage_stack(int symbol)
{
	float	tmp;

	tmp = this->_stack_rpn.top();
	this->_stack_rpn.pop();
	if (symbol == '+')
		tmp = this->_stack_rpn.top() + tmp;
	if (symbol == '-')
		tmp = this->_stack_rpn.top() - tmp;
	if (symbol == '*')
		tmp = this->_stack_rpn.top() * tmp;
	if (symbol == '/')
	{
		if (tmp == 0)
			return false;
		tmp = this->_stack_rpn.top() / tmp;
	}
	this->_stack_rpn.pop();
	this->_stack_rpn.push(tmp);
	return true;
}

void	ReversePolishNotation::print_result(void) const
{
	std::cout << this->_stack_rpn.top() << std::endl;
}
