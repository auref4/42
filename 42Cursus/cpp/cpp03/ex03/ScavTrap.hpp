#ifndef	SCAVTRAP_HPP
#define	SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap
{
	public :

	ScavTrap();										//CANONICAL
	ScavTrap(std::string const name);
	ScavTrap(ScavTrap const &src);					//CANONICAL
	~ScavTrap();									//CANONICAL

	ScavTrap&	operator=(ScavTrap const &rhs);		//CANONICAL

	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif
