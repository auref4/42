/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:32:04 by auferran          #+#    #+#             */
/*   Updated: 2022/09/18 20:03:20 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp1;

	tmp1 = *a;
	*a = *a / *b;
	*b = tmp1 % *b;
}
/*int     main(void)
{
        int     a;  
        int     b;  

        a = 10; 
        b = 5;
        ft_ultimate_div_mod(&a, &b);
        printf("a = %i\nb = %i\n", a, b); 
}*/
