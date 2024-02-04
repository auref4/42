#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	public :

	Weapon();
	Weapon(const std::string name);
	~Weapon();

	void				setType(const std::string str);
	const std::string&	getType(void) const;

	private :

	std::string	m_type;
};

#endif
