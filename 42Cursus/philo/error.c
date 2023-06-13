#include "philo.h"

void	error(int nb)
{
	if (nb == 0)
		printf("incorrect number of arguments.\n");
	if (nb == 1)
		printf("incorrect arguments, positive integers are required.\n");
	if (nb == 2)
		printf("the intenger should be between INT_MIN and INT_MAX\n");
}
