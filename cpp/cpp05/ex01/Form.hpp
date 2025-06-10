#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public :

	Form();																				//CANONICAL
	Form(std::string const name, int const grade_to_sign, int const grade_to_execute);
	Form(Form const &src);																//CANONICAL
	~Form();																			//CANONICAL

	Form&	operator=(Form const &rhs);													//CANONICAL

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;
	void		beSigned(Bureaucrat const &x);

	class	GradeTooHighException : public std::exception
	{
		public:

		virtual const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public :

		virtual const char*	what() const throw();
	};
	class	FormAlreadySigned : public std::exception
	{
		public :

		virtual const char*	what() const throw();
	};

	private :

	std::string const	m_name;
	bool				m_signed;
	const int			m_grade_to_sign;
	const int			m_grade_to_execute;
};

std::ostream&	operator<<(std::ostream &i, Form const &rhs);

#endif
