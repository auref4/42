#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class	RobotomyRequestForm : public	AForm
{
	public :

	RobotomyRequestForm();														//CANONICAL
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &src);						//CANONICAL
	~RobotomyRequestForm();														//CANONICAL

	RobotomyRequestForm&	operator=(RobotomyRequestForm const &rhs);			//CANONICAL

	private :

	void	execute(Bureaucrat const & executor) const;
};

#endif
