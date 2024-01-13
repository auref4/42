#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	public :

	Weapon();
	Weapon(const std::string &name);
	~Weapon();

	void		setType(std::string str);
	std::string	getType(void) const;

	private :

	std::string	m_type;
};

#endif
