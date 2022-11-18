/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:37:41 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/02 21:12:33 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define SEP " "
# include <stdlib.h>

char	**ft_read(char *file_name);
void	ft_putstr(int fd, char *str);
void	ft_free_read(char **a_s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_dict(char **str, char *z);
int		ft_strlen(char *str);
int		ft_convert(char **a_s, char *nbr);
char	*ft_strcat(char *dest, char *src, int f);
char	*level1(char **a_s, char *nbr, char *str);
char	*level2(char **a_s, char *nbr, char *str);
char	*level3(char **a_s, char *nbr, char *str);
char	*triple0(char **a_s, char *nbr, char *str);
char	*level(char **a_s, char *nbr, char *str);
int		len(char *str);
char	*ft_strdup(char *src);
int		ft_max_len(char **a_s);
int		ft_check_key(char *str);
char	*get_key(char *str);

#endif
