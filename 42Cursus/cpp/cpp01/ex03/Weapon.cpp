#include "Weapon.hpp"

Weapon::Weapon() : m_type("no weapon")
{

}

Weapon::Weapon(const std::string &name) : m_type(name)
{
	std::cout<<m_type<<" weapon is created"<<std::endl;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string str)
{
	m_type = str;
}

std::string	Weapon::getType(void) const
{
	return (m_type);
}
