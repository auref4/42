#ifndef	ANIMAL_HPP
#define	ANIMAL_HPP

#include <iostream>

class	Animal
{
	public:

	Animal();									// CANONICAL
	Animal(Animal const &src);					// CANONICAL
	virtual ~Animal();							// CANONICAL

	Animal&	operator=(Animal const &rhs);		// CANONICAL

	std::string		getType(void) const;
	virtual void	makeSound(void) const;

	protected :

	std::string	m_type;
};

#endif
