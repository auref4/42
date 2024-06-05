#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class	RobotomyRequestForm : public	AForm
{
	public :

	RobotomyRequestForm();														//CANONICAL
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &src);						//CANONICAL
	~RobotomyRequestForm();														//CANONICAL

	RobotomyRequestForm&	operator=(RobotomyRequestForm const &rhs);			//CANONICAL

	void	execute(Bureaucrat const & executor) const;
};

#endif
