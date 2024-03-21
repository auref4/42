#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public :

	MateriaSource();											//CANONICAL
	MateriaSource(MateriaSource const &src);					//CANONICAL
	~MateriaSource();											//CANONICAL

	MateriaSource&	operator=(MateriaSource const &rhs);		//CANONICAL

	void		learnMateria(AMateria *m);
	AMateria*	createMateria(std::string const &type);

	private :

	AMateria	*m_items[4];
};

#endif
