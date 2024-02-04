#include "Weapon.hpp"

Weapon::Weapon() : m_type("no weapon")
{

}

Weapon::Weapon(const std::string name) : m_type(name)
{
	std::cout<<m_type<<" weapon is created"<<std::endl;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(const std::string str)
{
	m_type = str;
}

const std::string&	Weapon::getType(void) const
{
	return m_type;
}
