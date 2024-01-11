#include "Zombie.h"

int	main(void)
{
	int	nb = 10;
	Zombie	*z;

	try
	{
		z = zombieHorde(nb, "foo");
	}
	catch(std::exception &error)
	{
		std::cout<<"ALLOC FAILURE "<<error.what()<<std::endl;
		return(0);
	}
	delete[] z;

	return (0);
}
