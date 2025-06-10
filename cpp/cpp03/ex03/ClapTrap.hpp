#ifndef	CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public :

	ClapTrap();										//CANONICAL
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const &src);					//CANONICAL
	~ClapTrap();									//CANONICAL

	ClapTrap&	operator=(ClapTrap const &rhs);		//CANONICAL

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	protected :

	std::string	m_name;
	int			m_hit_point;
	int			m_energy_point;
	int			m_attack_damage;
};

#endif
