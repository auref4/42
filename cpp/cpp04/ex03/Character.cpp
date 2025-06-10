#include "Character.hpp"

//CONSTRUCTOR

Character::Character() : ICharacter(), m_name("Unknown")
{
	std::cout << "Character default constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		m_items[i] = NULL;
}

Character::Character(std::string const name) : ICharacter(), m_name(name)
{
	std::cout << "Character string constructor called" << std::endl;

	for (int i = 0; i < 4; i++)
		m_items[i] = NULL;
}

Character::Character(Character const &src) : ICharacter(src), m_name(src.m_name)
{
	std::cout << "Character copy constructor called" << std::endl;

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
}

//DESTRUCTOR

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (m_items[i])
		{
			delete m_items[i];
			m_items[i] = NULL;
		}
	}
}

//OPERATOR

Character&	Character::operator=(Character const &rhs)
{
	std::cout << "Character operator '=' called" << std::endl;

	if (this != &rhs)
	{
		this->m_name = rhs.m_name;
		for (int i = 0; i < 4; i++)
			this->m_items[i] = rhs.m_items[i];
	}
	return *this;
}

//MEMBER FUNCTIONS

std::string const&	Character::getName(void) const
{
	return this->m_name;
}

void	Character::equip(AMateria *m)
{
	int	i = 0;

	while (i < 4)
	{
		if (m_items[i] == NULL)
		{
			m_items[i] = m;
			std::cout << m_name << " equip " << m->getType() << " materia" << std::endl;
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << m_name << " inventory is full "<< std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (m_items[idx])
		{
			m_items[idx] = NULL;
			std::cout << m_name << " unequip materia number " << idx << std::endl;
		}
		else
			std::cout << "No materia at this index to disequip" << std::endl;
	}
	else
		std::cout << "Index should be betwin 0 and 3" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (m_items[idx])
			m_items[idx]->use(target);
		else
			std::cout << "No materia at this index to use" << std::endl;
	}
	else
		std::cout << "Index should be betwin 0 and 3" << std::endl;
}
