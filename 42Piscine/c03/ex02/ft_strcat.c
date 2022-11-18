/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:51:28 by auferran          #+#    #+#             */
/*   Updated: 2022/09/25 15:34:28 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}	
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}	
		dest[j] = '\0';
	return (dest);
}

/*
int	main(void)
{
	char	src[] = "en ce moment";
	char	dest[100] = "je fais beaucoup de test ";	

	printf("%s\n", ft_strcat(dest, src));
}
*/
