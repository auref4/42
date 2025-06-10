#ifndef	INTERN_HPP
#define	INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public :

	Intern();									//CANONICAL
	Intern(Intern const &src);					//CANONICAL
	~Intern();									//CANONICAL

	Intern&	operator=(Intern const &rhs);		//CANONICAL

	AForm*	makeForm(std::string const name, std::string const target) const;
	AForm*	makeShrubberyCreationForm(std::string const target) const;
	AForm*	makeRobotomyRequestForm(std::string const target) const;
	AForm*	makePresidentialPardonForm(std::string const target) const;

	class	IncorrectName : public std::exception
	{
		public:

		virtual const char*	what() const throw();
	};
};

#endif
