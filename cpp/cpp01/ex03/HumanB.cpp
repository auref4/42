#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : m_name(name), m_weapon(NULL)
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
	if (m_weapon == NULL)
	{
		std::cout<<m_name<<" doesn't have a weapon"<<std::endl;
		return ;
	}
	tmp = m_weapon->getType();
	std::cout<<m_name<<" attack with their "<<tmp<<std::endl;
}
