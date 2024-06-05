#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class	ShrubberyCreationForm : public	AForm
{
	public :

	ShrubberyCreationForm();														//CANONICAL
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);						//CANONICAL
	~ShrubberyCreationForm();														//CANONICAL

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &rhs);			//CANONICAL

	void	execute(Bureaucrat const & executor) const;
};

#endif
