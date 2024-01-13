#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : m_name(name)
{
	std::cout<<m_name<<" with no weapon is created"<<std::endl;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::string	tmp;

	tmp = m_weapon->getType();
	std::cout<<m_name<<" attack with their "<<tmp<<std::endl;
}
