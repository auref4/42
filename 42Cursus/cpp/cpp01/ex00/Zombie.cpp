#include "Zombie.h"

Zombie::Zombie(const std::string name) : m_name(name)
{
	std::cout<<m_name<<" Zombie created"<<std::endl;
}

Zombie::~Zombie()
{
	std::cout<<m_name<<" Zombie deleted"<<std::endl;
}

void	Zombie::announce(void) const
{
	std::cout<<m_name<<" : BraiiiiiiinnnzzzZ..."<<std::endl;
}
