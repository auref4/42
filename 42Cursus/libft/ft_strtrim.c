/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:37:55 by auferran          #+#    #+#             */
/*   Updated: 2022/11/21 20:07:15 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_left;
	size_t	len_right;
	size_t	i;
	char	*dest;

	len_left = 0;
	if (!s1 || !set)
		return (NULL);
	len_right = ft_strlen(s1) - 1;
	while (s1[len_left] && !check_set(s1[len_left], set))
		len_left++;
	while (s1[len_right] && !check_set(s1[len_right], set))
		len_right--;
	dest = malloc(sizeof(char) * (len_right - len_left + 1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (len_left <= len_right)
	{
		dest[i] = s1[len_left];
		i++;
		len_left++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;

	s1 = ft_strtrim("   xxx   xxx", " i");
	printf("ft_strtrim = %s\n", s1);
}
*/
