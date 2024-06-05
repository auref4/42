#include "Form.hpp"

//CONSTRUCTOR

Form::Form() : m_name("Unknow"), m_signed(false), m_grade_to_sign(150), m_grade_to_execute(150)
{
	std::cout << "Aform default constructor called" << std::endl;
}

Form::Form(std::string const name, int const grade_to_sign, int const grade_to_execute) : m_name(name), m_signed(false),
m_grade_to_sign(grade_to_sign), m_grade_to_execute(grade_to_execute)
{
	std::cout << "Aform assignement constructor called" << std::endl;

	if (grade_to_sign > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_execute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &src) : m_name(src.m_name), m_signed(false), m_grade_to_sign(src.m_grade_to_sign),
m_grade_to_execute(src.m_grade_to_execute)
{
	std::cout << "Aform copy constructor called" << std::endl;
}

//DESTRUCTOR

Form::~Form()
{
	std::cout << "Aform default destructor called" << std::endl;
}

//OPERATOR

Form& Form::operator=(Form const &rhs)
{
	(void) rhs;

	std::cout << "Aform assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

std::string	Form::getName(void) const
{
	return this->m_name;
}

std::string	Form::getName(void) const
{
	return this->m_target;
}

bool	Form::getSigned(void) const
{
	return this->m_signed;
}

int	Form::getGradeToSign(void) const
{
	return this->m_grade_to_sign;
}

int	Form::getGradeToExecute(void) const
{
	return this->m_grade_to_execute;
}

void	Form::beSigned(Bureaucrat const &x)
{
	int	bureaucrat_grade = x.getGrade();

	if (this->m_signed == true)
		throw Form::FormAlreadySigned();
	else if (bureaucrat_grade <= this->m_grade_to_sign)
	{
		this->m_signed = true;
		x.signForm(*this, this->m_signed);
	}
	else
	{
		x.signForm(*this, this->m_signed);
		throw Form::GradeTooHighException();
	}
}

void	Form::checkRequirements(Bureaucrat const &x)
{
	if (this->m_signed == true)
		throw Form::FormAlreadySigned();
	if (this->m_grade_to_execute < x.getGradeToExecute())
		throw Form::GradeTooHighException();
}

//EXCEPTIONS

const char*	Form::GradeTooHighException::what() const throw()
{
	return "(Form) Impossible, the grade is to high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "(Form) Impossible, the grade is to low";
}
const char*	Form::FormAlreadySigned::what() const throw()
{
	return "Form already signed";
}

//OSTREAM OPERATOR

std::ostream&	operator<<(std::ostream &i, Form const &rhs)
{
	i << rhs.getName() << " Form :" << std::endl <<
	"Bool signed : " << rhs.getSigned() << std::endl <<
	"Grade to sign : " << rhs.getGradeToSign() << std::endl <<
	"Grade to execute : " << rhs.getGradeToExecute() << std::endl;

	return i;
}
