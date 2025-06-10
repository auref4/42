#ifndef	ICE_HPP
#define	ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{
	public :

	Ice();								//CANONICAL
	Ice(Ice const &src);				//CANONICAL
	~Ice();								//CANONICAL

	Ice	&operator=(Ice const &rhs);		//CANONICAL

	AMateria*	clone(void) const;
};

#endif
