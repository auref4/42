/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:35:46 by auferran          #+#    #+#             */
/*   Updated: 2022/11/17 18:59:14 by auferran         ###   ########.fr       */
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

static int	ft_current_word(char const *s, char c, int index)
{
	int	i;
	int	current_word;

	i = 1;
	current_word = 0;
	if (s[0] != c)
		current_word = 1;
	while (i <= index)
	{
		if (s[i - 1] == c && s[i] != c)
			current_word++;
		i++;
	}
	return (current_word);
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
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			j++;
		i++;
	}
	return (j);
}

static void	ft_recurswords(char **dest, char const *s, char c, int index)
{
	int	len_word;
	int	j;
	int	current_word;

	j = 0;
	len_word = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index + len_word] && s[index + len_word] != c)
		len_word++;
	current_word = ft_current_word(s, c, index);
	current_word -= 1;
	dest[current_word] = malloc(sizeof(char) * (len_word + 1));
	if (!dest)
	{
		free_dest(dest);
		return ;
	}
	while (j < len_word)
	{
		dest[current_word][j++] = s[index++];
	}
	dest[current_word][len_word] = '\0';
	if (current_word + 1 != ft_nb_words(s, c))
		ft_recurswords(dest, s, c, index);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		nb_words;
	char	**dest;

	index = 0;
	if (s == NULL)
		return (NULL);
	nb_words = ft_nb_words(s, c);
	dest = malloc(sizeof(char *) * (nb_words + 1));
	if (!dest)
		return (NULL);
	if (nb_words == 0)
	{
		*dest = NULL;
		return (dest);
	}
	ft_recurswords(dest, s, c, index);
	if (!dest)
		return (NULL);
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
	dest = ft_split("", 'z');
	while (dest[i])
	{
		printf("ft_split = %s\n", dest[i]);
		i++;
	}
}
*/
/*
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int	main(void)
{
	char	**dest;
	char	*str;
	int	i;

	str = malloc(2000000001);
	str[2000000000] = 0;
	int fd = open("/tmp/coucou", O_RDONLY);
	fd = read(fd, str, 2000000000);
	i = 0;
	printf("a %d\n", fd);
	dest = ft_split(str, '\n');
	while (dest[i])
	{
		printf("ft_split = %s\n", dest[i]);
		i++;
	}
}
*/
