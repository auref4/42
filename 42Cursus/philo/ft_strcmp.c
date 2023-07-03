#include "philo.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t			i;
	unsigned char	*ufirst;
	unsigned char	*usecond;

	i = 0;
	ufirst = (unsigned char *)first;
	usecond = (unsigned char *)second;
	while (ufirst[i] && usecond[i] && ufirst[i] == usecond[i])
		i++;
	return (ufirst[i] - usecond[i]);
}
