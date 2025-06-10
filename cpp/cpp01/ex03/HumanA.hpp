#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class	HumanA
{
	public :

	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();

	void	attack(void) const;

	private :

	std::string	m_name;
	Weapon	&m_weapon;
};

#endif
