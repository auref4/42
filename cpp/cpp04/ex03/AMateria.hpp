#ifndef	AMATERIA_HPP
#define	AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	public :

	AMateria();										//CANONICAL
	AMateria(AMateria const &src);					//CANONICAL
	AMateria(std::string const &type);
	virtual ~AMateria();							//CANONICAL

	AMateria	&operator=(AMateria const &rhs);	//CANONICAL

	std::string const	&getType(void) const;

	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);

	protected :

	std::string	m_type;
};

#endif
