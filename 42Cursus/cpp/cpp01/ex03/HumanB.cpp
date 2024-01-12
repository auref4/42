#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : m_name(name)
{
	std::string	tmp;

	tmp = m_weapon.getType();
	std::cout<<m_name<<" with "<<tmp<<" are created"<<std::endl;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon weapon)
{
	std::string	tmp;

	tmp = weapon.getType();
	m_weapon.setType(tmp);
}

void	HumanB::attack(void) const
{
	std::string	tmp;

	tmp = weapon.getType();
	std::cout<<m_name<<" attack with their "<<tmp<<std::endl;
}
