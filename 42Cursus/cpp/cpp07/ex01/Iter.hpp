#ifndef	ITER_HPP
#define	ITER_HPP

#include <iostream>

template <typename T, typename F>
void	iter(T *array, int length, F function)
{
	int	i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

#endif
