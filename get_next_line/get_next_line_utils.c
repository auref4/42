/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:05:49 by auferran          #+#    #+#             */
/*   Updated: 2023/01/11 17:38:21 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char **src)
{
	char	*dest;
	size_t	len;
	int		i;

	len = ft_strlen(*src);
	if (len == 0)
	{
		dest = NULL;
		free(*src);
		return (dest);
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while ((*src)[i])
	{
		dest[i] = (*src)[i];
		i++;
	}
	free(*src);
	*src = NULL;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dest;

	i = 0;
	j = 0;
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
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (free(s1), free(s2), dest);
}

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	i;
	size_t	len2;
	char	*dest;

	if (start >= ft_strlen(s))
		len2 = 0;
	else
		len2 = ft_strlen(&s[start]);
	if (len2 > len)
		len2 = len;
	dest = malloc(sizeof(char) * (len2 + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len2)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strchr(char *str, char searchedChar)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == searchedChar)
			return (i);
		i++;
	}
	return (-1);
}
