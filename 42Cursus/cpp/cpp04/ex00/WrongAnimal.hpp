#ifndef	WRONGANIMAL_HPP
#define	WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	public:

	WrongAnimal();											// CANONICAL
	WrongAnimal(WrongAnimal const &src);					// CANONICAL
	virtual ~WrongAnimal();									// CANONICAL

	WrongAnimal&	operator=(WrongAnimal const &rhs);		// CANONICAL

	std::string	getType(void) const;
	void		makeSound(void) const;

	protected :

	std::string	m_type;
};

#endif
