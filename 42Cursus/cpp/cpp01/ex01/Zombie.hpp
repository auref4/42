#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class	Zombie
{
	public:

	Zombie();
	~Zombie();

	void	announce(void) const;
	void	SetName(std::string str);

	private:

	std::string	m_name;
};

#endif
