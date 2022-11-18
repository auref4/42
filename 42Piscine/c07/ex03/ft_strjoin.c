/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:29:22 by auferran          #+#    #+#             */
/*   Updated: 2022/10/06 13:41:13 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[i + j] = src[i];
		i++;
	}
	return (dest);
}

int	ft_bigstrlen(char **strs, char *sep, int size)
{
	int	i;
	int	len;

	len = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*voidtrash;
	int		i;
	char	*dest;

	if (size == 0)
	{
		voidtrash = malloc (sizeof(char));
		if (!voidtrash)
			return (NULL);
		voidtrash = "\0";
		return (voidtrash);
	}
	len = ft_bigstrlen(strs, sep, size);
	dest = malloc (sizeof * dest * (len + 1));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(dest, sep);
		ft_strcat(dest, strs[i++]);
	}
	return (dest);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argc, argv, "---"));
	return (0);
}

