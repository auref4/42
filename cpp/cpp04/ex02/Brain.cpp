#include "Brain.hpp"

// OPERATOR

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	for (int i = 0; i < 100; i++)
		this->m_ideas[i] = src.m_ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

// DESTRUCTOR

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// OPERATOR

Brain&	Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->m_ideas[i] = rhs.m_ideas[i];
	}
	std::cout << "Brain operator '=' called" << std::endl;
	return *this;
}
