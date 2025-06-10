#ifndef	ICHARACTER_HPP
#define	ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	public :

	ICharacter();										//CANONICAL
	ICharacter(ICharacter const &src);					//CANONICAL
	virtual ~ICharacter();								//CANONICAL

	ICharacter	&operator=(ICharacter const &rhs);		//CANONICAL

	virtual std::string const	&getName(void) const = 0;
	virtual void				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

#endif
