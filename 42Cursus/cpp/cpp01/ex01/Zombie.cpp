#include "Zombie.h"

Zombie::Zombie()
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

void	Zombie::SetName(std::string str)
{
	m_name = str;
}
