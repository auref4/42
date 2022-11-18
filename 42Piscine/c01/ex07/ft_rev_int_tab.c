/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:23:43 by auferran          #+#    #+#             */
/*   Updated: 2022/09/19 17:00:33 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}	

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i != size / 2)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}

/*
int	main(void)
{
	int	tab[] = {9,8,7,6,5,4,3,2,1,0};
	int	i;

	i = 0;
	ft_rev_int_tab(tab, 10);
	while (i < 10)
	{
		printf("%i, ", tab[i]);
		i++;
	}
}
*/
