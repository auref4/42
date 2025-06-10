#ifndef	BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
	public:

	Bureaucrat();										//CANONICAL
	Bureaucrat(std::string const name, int const nb);
	Bureaucrat(Bureaucrat const &src);					//CANONICAL
	~Bureaucrat();										//CANONICAL

	Bureaucrat&	operator=(Bureaucrat const &rhs);		//CANONICAL

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);

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

	private :

	std::string	const	m_name;
	int					m_grade;
};

std::ostream&	operator<<(std::ostream &i, Bureaucrat const &rhs);

#endif
