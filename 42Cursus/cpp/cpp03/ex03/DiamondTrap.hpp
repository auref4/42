#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public :

	DiamondTrap();										//CANONICAL
	DiamondTrap(std::string const name);
	DiamondTrap(DiamondTrap const &src);				//CANONICAL
	~DiamondTrap();										//CANONICAL

	DiamondTrap&	operator=(DiamondTrap const &rhs);	//CANONICAL

	void	call_ScavAttack(std::string const name);
	void	whoAmi(void);

	private :

	std::string	m_name;
};

#endif
