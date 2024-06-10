#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>
#include <cstring>

class	ShrubberyCreationForm : public	AForm
{
	public :

	ShrubberyCreationForm();														//CANONICAL
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);						//CANONICAL
	~ShrubberyCreationForm();														//CANONICAL

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &rhs);			//CANONICAL

	private :

	void	execute(Bureaucrat const & executor) const;
};

#endif
