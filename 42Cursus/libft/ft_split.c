/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:35:46 by auferran          #+#    #+#             */
/*   Updated: 2022/11/21 15:33:47 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_dest(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free (dest);
}

int	ft_lenwords(char const *s, char c, int index)
{
	int	len;

	len = 0;
	while (s[index] && s[index] != c)
	{
		index++;
		len++;
	}
	return (len);
}

int	ft_nb_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (s[0] == 0)
		return (0);
	if (s[0] != c)
		j = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			j++;
		i++;
	}
	return (j);
}

void	ft_split_words(char const *s, char c, char **dest, int current_words)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && current_words < ft_nb_words(s, c))
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		dest[current_words] = malloc(sizeof(char) * (ft_lenwords(s, c, i) + 1));
		if (!dest)
		{
			free_dest(dest);
			return ;
		}
		while (s[i] && s[i] != c)
		{
			dest[current_words][j] = s[i];
			j++;
			i++;
		}
		dest[current_words][j] = '\0';
		current_words++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		nb_words;
	int		current_words;

	current_words = 0;
	nb_words = ft_nb_words(s, c);
	dest = malloc(sizeof(char *) * (nb_words + 1));
	if (nb_words > 0)
		ft_split_words(s, c, dest, current_words);
	dest[nb_words] = NULL;
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**dest;
	int	i;

	i = 0;
	dest = ft_split("test de fou furieux", ' ');
	while (dest[i])
	{
		printf("ft_split = %s\n", dest[i]);
		free(dest[i]);
		i++;
    }
	free(dest);
}
*/
