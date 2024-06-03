#include "Form.hpp"

//CONSTRUCTOR

Form::Form() : m_name("Unknow"), m_signed(false), m_grade_to_sign(150), m_grade_to_execute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : m_name(name), m_signed(false),
m_grade_to_sign(grade_to_sign), m_grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_execute < 1)
		throw Form::GradeTooHighException();

	std::cout << "Assignement constructor called" << std::endl;
}

Form::Form(Form const &src) : m_name(src.m_name), m_signed(false), m_grade_to_sign(src.m_grade_to_sign),
m_grade_to_execute(src.m_grade_to_execute)
{
	std::cout << "Copy constructor called" << std::endl;
}

//DESTRUCTOR

Form::~Form()
{
	std::cout << "Default destructor called" << std::endl;
}

//OPERATOR

Form& Form::operator=(Form const &rhs)
{
	(void) rhs;

	std::cout << "Assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

std::string	Form::getName(void) const
{
	return this->m_name;
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

void	Form::beSigned(Bureaucrat &x)
{
	int	bureaucrat_grade = x.getGrade();

	if (this->m_signed == true)
		std::cout << "Form " << this->m_name << " already signed" << std::endl;
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

//EXCEPTIONS

const char*	Form::GradeTooHighException::what() const throw()
{
	return "(Form) Impossible, the grade is to high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "(Form) Impossible, the grade is to low";
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
