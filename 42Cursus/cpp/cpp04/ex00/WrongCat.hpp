#ifndef	WRONGCAT_HPP
#define	WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public :

	WrongCat();										// CANONICAL
	WrongCat(WrongCat const &src);					// CANONICAL
	~WrongCat();									// CANONICAL

	WrongCat&	operator=(WrongCat const &rhs);		// CANONICAL

	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif
