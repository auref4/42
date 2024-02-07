#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	public :

	Dog();									// CANONICAL
	Dog(Dog const &src);					// CANONICAL
	~Dog();									// CANONICAL

	Dog&	operator=(Dog const &rhs);		// CANONICAL

	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif
