#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public :

	Dog();									// CANONICAL
	Dog(Dog const &src);					// CANONICAL
	~Dog();									// CANONICAL

	Dog&	operator=(Dog const &rhs);		// CANONICAL

	std::string	getType(void) const;
	void		makeSound(void) const;

	private :

	Brain	*m_brain;
};

#endif
