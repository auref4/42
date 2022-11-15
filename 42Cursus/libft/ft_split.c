/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:35:46 by auferran          #+#    #+#             */
/*   Updated: 2022/11/15 18:14:07 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recurswords(char **dest, char const *s, char c, int index)
{
	int	j;
	int	x;
	int	len_word;
	int	current_word;

	len_word = 0;
	j = 0;
	while (s[j] == c)
		j++;
	while (s[j + len_word] != c)
	{
		len_word++;
		index++;
	}
	current_word = ft_current_word(s, c, index)
	dest[current_word] = malloc(sizeof(char) * (len_word + 1));
	x = 0;
	if (j < len_word)
	{
		dest[current_word][x] = s[j]
		x++;
		j++;
	}
	dest[current_word][x] = '\0';
	else if
		current_word++;
	ft_recurswords(dest, s, c, index);
}

static int	ft_current_word(char const *s, char c, int index)
{
	int	i;
	int	current_word;

	i = 1;
	current_word = 0;
	if (s[0] != c)
		current_word = 1;
	while (i < index)
	{
		if (s[i - 1] == c && s[i] != c)
			current_word++;
		i++;
	}
	return (current_word);

}

static int	ft_nb_words(char const *s, char c)
{
	int	index;
	int	j;

	i = 1;
	j = 0;
	if (s[0] != c)
		j = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	nb_words;
	char	**dest;

	index = 0;
	if (s == NULL)
		return (NULL);
	nb_words = ft_nb_words(s,c);
	dest = malloc(sizeof(char) * (nb_words + 1));
	if (!dest)
		return (NULL);
	ft_recurswords(dest, s, c, index);
	return (dest);
}
