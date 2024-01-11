#include "Zombie.h"

Zombie*	newZombie(const std::string &name)
{
	Zombie	*z = new Zombie(name);

	return (z);
}
