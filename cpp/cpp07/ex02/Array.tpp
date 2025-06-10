#include "Array.hpp"

//CONSTRUCTORS

template<typename T>
Array<T>::Array() : elements(NULL), nb_elements(0)
{
	std::cout << "Array default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n) : nb_elements(n)
{
	std::cout << "Array assignement constructor called" << std::endl;
	this->elements = new T[this->nb_elements];
}

template<typename T>
Array<T>::Array(Array<T> const &src) : nb_elements(src.nb_elements)
{
	std::cout << "Array copy constructor called" << std::endl;
	this->elements = new T[this->nb_elements];
	for (unsigned int i = 0; i < this->nb_elements; i++)
		this->elements[i] = src.elements[i];
}

//DESTRUCTOR

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array default destructor called" << std::endl;
	delete[] this->elements;
}

//OPERATORS

template<typename T>
Array<T>&	Array<T>::operator=(Array<T> const &rhs)
{
	std::cout << "Array copy operator called" << std::endl;

	if (this->elements != &rhs)
		delete[] this->elements;
	this->nb_elements = rhs.nb_elements;
	this->elements = new T[this->nb_elements];
	for (unsigned int i = 0; i < this->nb_elements; i++)
		this->elements[i] = rhs.elements[i];
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= this->nb_elements)
		throw IncorrectIndex();
	return this->elements[index];
}

//MEMBER FUNCTION

template<typename T>
unsigned int	Array<T>::size() const
{
	return this->nb_elements;
}

//EXCEPTIONS

template<typename T>
const char*	Array<T>::IncorrectIndex::what() const throw()
{
	return "Incorrect index, impossible !";
}
