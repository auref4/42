#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class	IMateriaSource
{
	public :

	IMateriaSource();											//CANONICAL
	IMateriaSource(IMateriaSource const &src);					//CANONICAL
	virtual	~IMateriaSource();									//CANONICAL

	IMateriaSource&	operator=(IMateriaSource const &rhs);		//CANONICAL

	virtual void		learnMateria(AMateria *m) = 0;
	virtual AMateria*	createMateria(std::string const &type) = 0;
};

#endif
