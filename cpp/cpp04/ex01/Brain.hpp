#ifndef	BRAIN_HPP
#define	BRAIN_HPP

#include <iostream>

class	Brain
{
	public :

	Brain();									// CANONICAL
	Brain(Brain const &src);					// CANONICAL
	~Brain();									// CANONICAL

	Brain&	operator=(Brain const &rhs);		// CANONICAL

	std::string m_ideas[100];
};

#endif
