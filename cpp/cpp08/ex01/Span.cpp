#include "Span.hpp"

//CONSTRUCTOR

Span::Span() : m_n(0)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : m_n(n)
{
	std::cout << "Span Assignation constructor called" << std::endl;
}

Span::Span(Span const &src) : m_vec(src.m_vec), m_n(src.m_n)
{
	std::cout << "Span copy constructor called" << std::endl;

}

//DESTRUCTOR

Span::~Span()
{
	std::cout << "Span default destructor called" << std::endl;
}

//OPERATOR

Span&	Span::operator=(Span const &rhs)
{
	std::cout << "Span copy operator called" << std::endl;

	if (this->m_vec != rhs.m_vec)
	{
		this->m_vec = rhs.m_vec;
		this->m_n = rhs.m_n;
	}
	return *this;
}

//FUNCTIONS

void	Span::addNumber(int nb)
{
	if (this->m_vec.size() == this->m_n)
		throw FullElements();
	this->m_vec.push_back(nb);
}

void	Span::addMultipleNumbers(unsigned int range)
{
	for (unsigned int i = 0; i < range; i++)
		this->addNumber(i);
}

int	Span::shortestSpan() const
{
	if (this->m_vec.size() <= 1)
		throw VoidElements();
	std::vector<int>	tmp = this->m_vec;
	std::sort(tmp.begin(), tmp.end());
	int	shortest = tmp[1] - tmp[0];
	if (tmp.size() >= 3)
	{
		for (unsigned int i = 2; i < tmp.size(); i++)
		{
			if (tmp[i] - tmp[i - 1] < shortest)
				shortest = tmp[i] - tmp[i - 1];
		}
	}
	return shortest;
}

int	Span::longestSpan() const
{
	if (this->m_vec.size() <= 1)
		throw VoidElements();
	std::vector<int>::const_iterator	max = std::max_element(m_vec.begin(), m_vec.end());
	std::vector<int>::const_iterator	min = std::min_element(m_vec.begin(), m_vec.end());
	int	longest = *max - *min;
	return longest;
}

//EXCEPTIONS

const char*	Span::FullElements::what() const throw()
{
	return "Impossible, elements are full !";
}

const char*	Span::VoidElements::what() const throw()
{
	return "Impossible, only one element or none !";
}
