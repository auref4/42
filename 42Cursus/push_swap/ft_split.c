/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:48:28 by auferran          #+#    #+#             */
/*   Updated: 2023/03/04 00:48:29 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	ft_lenwords(char const *s, char c, int index)
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

static int	ft_nb_words(char const *s, char c)
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

static void	ft_split_words(char const *s, char c, char **dest, int actual_word)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && actual_word < ft_nb_words(s, c))
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		dest[actual_word] = malloc(sizeof(char) * (ft_lenwords(s, c, i) + 1));
		if (!dest)
		{
			free_dest(dest);
			return ;
		}
		while (s[i] && s[i] != c)
		{
			dest[actual_word][j] = s[i];
			j++;
			i++;
		}
		dest[actual_word][j] = '\0';
		actual_word++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		nb_words;
	int		actual_word;

	actual_word = 0;
	if (!s)
		return (NULL);
	nb_words = ft_nb_words(s, c);
	dest = malloc(sizeof(char *) * (nb_words + 1));
	if (nb_words > 0)
		ft_split_words(s, c, dest, actual_word);
	dest[nb_words] = NULL;
	return (dest);
}
