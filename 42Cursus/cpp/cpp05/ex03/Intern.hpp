#ifndef	INTERN_HPP
#define	INTERN_HPP

#include "AForm.hpp"

class	Intern
{
	public :

	Intern();									//CANONICAL
	Intern(Intern const &src);					//CANONICAL
	~Intern();									//CANONICAL

	Intern&	operator=(Intern const &rhs);		//CANONICAL

	Aform*	makeForm(std::string const name, std::string const target) const;
};

#endif
