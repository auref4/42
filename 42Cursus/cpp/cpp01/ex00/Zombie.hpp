#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class	Zombie
{
	public:

	Zombie(const std::string &name);
	~Zombie();

	void	announce(void) const;

	private:

	std::string	m_name;
};

#endif
