/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:26:58 by auferran          #+#    #+#             */
/*   Updated: 2023/01/11 18:01:26 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif
# include <stdlib.h>
# include <unistd.h>

char	*verif_n(int n, char **save);
int		verif_read(char *buff, char **save, int fd, int *r);
char	*verif_save(char **save, char *buff);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char **src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, size_t len);
int		ft_strchr(char *str, char searchedChar);
#endif
