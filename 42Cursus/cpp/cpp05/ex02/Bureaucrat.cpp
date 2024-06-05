#include "Bureaucrat.hpp"

//CONSTRUCTOR

Bureaucrat::Bureaucrat() : m_name("Unknow"), m_grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int nb) : m_name(name)
{
	std::cout << "Assignement constructor called" << std::endl;

	if (nb > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (nb < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade = nb;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : m_name(src.m_name), m_grade(src.m_grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

//DESTRUCTOR

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

//OPERATOR

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;

	(void) rhs;

	return *this;
}

//MEMBER FUNCTIONS

std::string	Bureaucrat::getName(void) const
{
	return m_name;
}

int	Bureaucrat::getGrade(void) const
{
	return m_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (m_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		m_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (m_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		m_grade += 1;
}

void	Bureaucrat::signForm(Form &x, bool y) const
{
	if (y == true)
		std::cout << "Bureaucrat " << this->m_name << " signed Form " << x.getName() << std::endl;
	else
		std::cout << "Bureaucrat " << this->m_name << " couldn't sign Form " << x.getName() <<
		" because the grade to sign is to high" << std::endl;
}

//EXCEPTIONS

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "(Bureaucrat) Impossible, the grade is to high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "(Bureaucrat) Impossible, the grade is to low";
}

//OSTREAM OPERATOR

std::ostream&	operator<<(std::ostream &i, Bureaucrat const &rhs)
{
	i << rhs.getName() << " bureaucrate grade " << rhs.getGrade() << std::endl;

	return i;
}
