#include "philo.h"

int	init_value(int argc, char **argv)
{
	t_value	*value;

	if (!ft_atoi(argv[1], &value->nb_of_p))
		return (0);
	if (!ft_atoi(argv[2], &value->t_to_d))
		return (0);
	if (!ft_atoi(argv[3], &value->t_to_e))
		return (0);
	if (!ft_atoi(argv[4], &value->t_to_s))
		return (0);
	if (argc == 6)
	{
		if (!ft_atoi(argv[5], &value->nb_of_t_e_p_m_e))
			return (0);
		if(value->nb_of_t_e_p_m_e < 1)
			return (error(1), 0);
	}
	else
		value->nb_of_t_e_p_m_e = 0;
	if (value->nb_of_p < 1 || value->t_to_d < 1 || value->t_to_e < 1
		|| value->t_to_s < 1)
		return (error(1), 0);
	return (1);
}

int	philo(int argc, char **argv)
{
	int		i;
	int		tid;

	i = 0;
	if(!init_value(argc, argv))
		return (0);
	while (i < value.nb_of_p)
	{
		tid = pthread_create()
	}
	/*printf("nb = %d\n", value.nb_of_p);
	printf("nb = %f\n", value.nb_of_f);
	printf("nb = %d\n", value.t_to_d);
	printf("nb = %d\n", value.t_to_e);
	printf("nb = %d\n", value.t_to_s);
	printf("nb = %d\n", value.nb_of_t_e_p_m_e);*/
	return (1);
}
