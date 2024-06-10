#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public	AForm
{
	public :

	PresidentialPardonForm();														//CANONICAL
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &src);						//CANONICAL
	~PresidentialPardonForm();														//CANONICAL

	PresidentialPardonForm&	operator=(PresidentialPardonForm const &rhs);			//CANONICAL

	private :

	void	execute(Bureaucrat const & executor) const;
};

#endif
