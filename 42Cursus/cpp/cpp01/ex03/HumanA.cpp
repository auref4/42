#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
	std::string	tmp;

	tmp = m_weapon.getType();
	std::cout<<m_name<<" with "<<tmp<<" is created"<<std::endl;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	std::string	tmp;

	tmp = m_weapon.getType();
	std::cout<<m_name<<" attack with their "<<tmp<<std::endl;
}
