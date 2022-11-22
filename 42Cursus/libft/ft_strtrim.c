/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:37:55 by auferran          #+#    #+#             */
/*   Updated: 2022/11/22 15:38:46 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_left;
	int		len_right;
	int		i;
	char	*dest;

	i = 0;
	len_left = 0;
	len_right = ft_strlen(s1) - 1;
	while (check_set(s1[len_right], set))
		len_right--;
	while (check_set(s1[len_left], set))
		len_left++;
	dest = ft_substr(s1, len_left, (len_right - len_left + 1));
	if (len_left > len_right)
	{
		dest[0] = '\0';
		return (dest);
	}
	if (dest == NULL)
		return (NULL);
	dest[len_right - len_left + 1] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;

	s1 = ft_strtrim("", "123");
	printf("ft_strtrim = %s\n", s1);
}
*/
