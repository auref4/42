#include "philo.h"

int	main(int argc, char **argv)
{
	if(argc == 5 || argc == 6)
	{
		if (!check_arg(argv))
			return (error (1), 0);
		if (!philo(argc, argv))
			return (0);
	}
	else
		return (error(0), 0);
	return (0);
}
