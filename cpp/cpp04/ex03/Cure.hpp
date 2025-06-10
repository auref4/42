#ifndef	CURE_HPP
#define	CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	public :

	Cure();										//CANONICAL
	Cure(Cure const &src);						//CANONICAL
	~Cure();									//CANONICAL

	Cure	&operator=(Cure const &rhs);		//CANONICAL

	AMateria*	clone(void) const;
};

#endif
