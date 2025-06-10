#ifndef	FRAGTRAP_HPP
#define	FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public :

	FragTrap();										//CANONICAL
	FragTrap(std::string const name);
	FragTrap(FragTrap const &src);					//CANONICAL
	~FragTrap();									//CANONICAL

	FragTrap&	operator=(FragTrap const &rhs);		//CANONICAL

	void	highFivesGuys(void);
};

#endif
