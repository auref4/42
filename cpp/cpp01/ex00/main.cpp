#include "Zombie.h"

int	main(void)
{
	Zombie	*z = newZombie("foo");

	z->announce();
	randomChump("foo2");
	delete z;

	return (0);
}
