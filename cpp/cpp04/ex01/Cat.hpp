#ifndef	CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	public :

	Cat();									// CANONICAL
	Cat(Cat const &src);					// CANONICAL
	~Cat();									// CANONICAL

	Cat&	operator=(Cat const &rhs);		// CANONICAL

	std::string	getType(void) const;
	void		makeSound(void) const;

	private :

	Brain	*m_brain;
};

#endif
