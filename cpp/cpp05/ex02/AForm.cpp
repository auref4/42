#include "AForm.hpp"

//CONSTRUCTOR

AForm::AForm() : m_name("Unknow"), m_target("Unknow"), m_signed(false), m_grade_to_sign(150), m_grade_to_execute(150)
{
	std::cout << "Aform default constructor called" << std::endl;
}

AForm::AForm(std::string const name, std::string const target, int const grade_to_sign, int const grade_to_execute) : m_name(name),
m_target(target), m_signed(false), m_grade_to_sign(grade_to_sign), m_grade_to_execute(grade_to_execute)
{
	std::cout << "Aform assignement constructor called" << std::endl;

	if (grade_to_sign > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_execute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const &src) : m_name(src.m_name), m_target(src.m_target), m_signed(false), m_grade_to_sign(src.m_grade_to_sign),
m_grade_to_execute(src.m_grade_to_execute)
{
	std::cout << "Aform copy constructor called" << std::endl;
}

//DESTRUCTOR

AForm::~AForm()
{
	std::cout << "Aform default destructor called" << std::endl;
}

//OPERATOR

AForm& AForm::operator=(AForm const &rhs)
{
	(void) rhs;

	std::cout << "Aform assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

std::string	AForm::getName(void) const
{
	return this->m_name;
}

std::string	AForm::getTarget(void) const
{
	return this->m_target;
}

bool	AForm::getSigned(void) const
{
	return this->m_signed;
}

int	AForm::getGradeToSign(void) const
{
	return this->m_grade_to_sign;
}

int	AForm::getGradeToExecute(void) const
{
	return this->m_grade_to_execute;
}

void	AForm::beSigned(Bureaucrat const &x)
{
	int	bureaucrat_grade = x.getGrade();

	if (this->m_signed == true)
		throw AForm::FormAlreadySigned();
	else if (bureaucrat_grade <= this->m_grade_to_sign)
	{
		this->m_signed = true;
		x.signForm(*this, this->m_signed);
	}
	else
	{
		x.signForm(*this, this->m_signed);
		throw AForm::GradeTooHighException();
	}
}

void	AForm::checkRequirements(Bureaucrat const &x) const
{
	if (this->m_signed == false)
		throw AForm::FormNotSigned();
	if (this->m_grade_to_execute < x.getGrade())
		throw AForm::GradeTooHighException();
}

//EXCEPTIONS

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "(AForm) Impossible, the grade is to high";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "(AForm) Impossible, the grade is to low";
}

const char*	AForm::FormAlreadySigned::what() const throw()
{
	return "AForm already signed";
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return "AForm not signed";
}

//OSTREAM OPERATOR

std::ostream&	operator<<(std::ostream &i, AForm const &rhs)
{
	i << rhs.getName() << " Form :" << std::endl <<
	"Target : " << rhs.getTarget() << std::endl <<
	"Bool signed : " << rhs.getSigned() << std::endl <<
	"Grade to sign : " << rhs.getGradeToSign() << std::endl <<
	"Grade to execute : " << rhs.getGradeToExecute() << std::endl;

	return i;
}
