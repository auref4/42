#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :

	MutantStack() : std::stack<T, Container>() {};								//CANONICAL
	MutantStack(MutantStack const &src) : std::stack<T, Container>(src) {};		//CANONICAL
	~MutantStack() {};															//CANONICAL
	MutantStack&	operator=(MutantStack const &rhs)							//CANONICAL
	{
		if (this != &rhs)
			std::stack<T, Container>::operator=(rhs);
		return *this;
	};
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	iterator	begin()
	{
		return std::stack<T, Container>::c.begin();
	};
	iterator	end()
	{
		return std::stack<T, Container>::c.end();
	};
};

#endif
