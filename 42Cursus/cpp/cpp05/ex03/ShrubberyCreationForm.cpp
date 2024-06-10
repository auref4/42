#include "ShrubberyCreationForm.hpp"

//CONSTRUCTORS

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", "Unknow", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreation", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm assignement constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

//DESTRUCTOR

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//OPERATOR

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void) rhs;

	std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;

	return *this;
}

//MEMBER FUNCTIONS

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkRequirements(executor);

	std::string		shrubbery = "_shrubbery";
	std::string		join = this->getTarget() + shrubbery;
	std::ofstream	ofs(join.c_str());

	if (ofs.is_open() == false)
		std::cerr << "outfile error" << std::endl;
	else
	{
		ofs << "       _-_" << "\n";
		ofs << "    {~~   ~~}" << "\n";
		ofs << " {~~         ~~}" << "\n";
		ofs << "{               }" << "\n";
		ofs << " {  _-     -_  }" << "\n";
		ofs << "   ~  {} {}  ~" << "\n";
		ofs << "_- -   { } _- _" << "\n";
		ofs << "  _ -  { }   -_" << "\n";
		ofs << "      {} {}" << "\n";
	}
	ofs.close();
}
