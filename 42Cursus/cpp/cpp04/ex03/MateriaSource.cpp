#include "MateriaSource.hpp"

//OPERATOR

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		m_items[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &src) : IMateriaSource(src)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_items[i])
			delete m_items[i];
		if (src.m_items[i])
		{
			m_items[i]->clone();
			m_items[i] = src.m_items[i];
		}
		else
			m_items[i] = NULL;
	}

	std::cout << "MateriaSource copy constructor called" << std::endl;
}

//DESTRUCTOR

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (m_items[i])
		{
			delete m_items[i];
			m_items[i] = NULL;
		}
	}

	std::cout << "MateriaSource destructor called" << std::endl;
}

//OPERATOR

MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
			this->m_items[i] = rhs.m_items[i];
	}
	return *this;

	std::cout << "MateriaSource operator '=' called" << std::endl;
}

//MEMBER FUNCTIONS

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i = 0;

	while (i < 4)
	{
		if (m_items[i] == NULL)
		{
			m_items[i] = m;
			std::cout << "Learn " << m->getType() << " materia" << std::endl;
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "Inventory is full "<< std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (m_items[i] && m_items[i]->getType() == type)
		{
			std::cout << "Create " << type << " materia"<< std::endl;
			return m_items[i]->clone();
		}
	}
	std::cout << "No type match"<< std::endl;
	return 0;
}
