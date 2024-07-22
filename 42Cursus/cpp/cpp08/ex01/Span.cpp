#include "Span.hpp"

//CONSTRUCTOR

Span::Span() : nb_elements(0), index_elements(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span()::Span(unsigned int n) : nb_elements(n), index_elements(0)
{
	std::cout << "Span Assignation constructor called" << std::endl;

	this->elements = new unsigned int[nb_elements];
}

Span()::Span(Span const &src) : nb_elements(src.nb_elements), index_elements(src.index_elements)
{
	std::cout << "Span copy constructor called" << std::endl;

	this->elements = new unsigned int[this->nb_elements];
	for (int i = 0; i < this->nb_elements; i++)
		this->elements[i] = src.elements[i];
}

//DESTRUCTOR

Span::~Span()
{
	std::cout << "Span default destructor called" << std::end;

	delete[] this->elements;
}

//OPERATOR

Span&	Span::operator=(Span const &rhs)
{
	std::cout << "Span copy operator called" << std::endl;

	if (this->elements != rhs.elements)
		delete[] this->elements;
	this->nb_elements = rhs.nb_elements;
	this->index_elements = rhs.nb_elements;
	this->elements = new unsigned int[this->nb_elements];
	for (int i = 0; i < this->nb_elements; i++)
		this->elements[i] = rhs.elements[i];
	return *this;
}

//FUNCTIONS

void	Span::addNumber(int nb)
{
	if (this->index_elements > this->nb_elements - 1)
		throw FullElements();
	this->elements[this->index_elements] = nb;
	this->index_elements += 1;
}

void	Span::addMultipleNumbers()
{

}

//EXCEPTIONS

const char*	Span::FullElements::what() const throw()
{
	return "Impossible, elements are full !";
}

const char*	Span::VoidElements::what() const throw()
{
	return "Impossible, only one element or none !"
}
