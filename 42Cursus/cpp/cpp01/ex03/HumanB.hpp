#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class	HumanB
{
	public :

	HumanB(const std::string &name);
	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack(void) const;

	private :

	std::string	m_name;
	Weapon	m_weapon;
};

#endif
