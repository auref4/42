#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public stack
{
	public :

	MutantStack();											//CANONICAL
	MutantStack(MutantStack const &src);					//CANONICAL
	~MutantStack();											//CANONICAL
	MutantStack&	operator=(MutantStack const &rhs);		//CANONICAL
}

#endif
