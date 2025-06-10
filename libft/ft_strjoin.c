/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:30:36 by auferran          #+#    #+#             */
/*   Updated: 2022/11/15 13:50:59 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i++] = s2[j++];
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*s1;

	if (argc == 3)
	{
		s1 = ft_strjoin(argv[1], argv[2]);
		printf("ft_strjoin = %s\n", s1);
	}
	else
		return (0);
}
*/
