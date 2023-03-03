/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:31:40 by auferran          #+#    #+#             */
/*   Updated: 2023/01/21 02:12:50 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>

typedef struct s_lst
{
	int	nb;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;
void		ft_error(void);
int			check_arg(char **argv);
void		*ft_calloc(size_t nmemb, size_t size);
void		free_dest(char **dest);
char		**ft_split(char const *s, char c);
int			ft_strlen(char *str);
int			is_digit(char c);
char		**prep_arg(char **str);
int			ft_atoi(const char *s, int *nb);
void		push_swap(char **dest);
int			ft_lst_size(t_lst *lst_a);
t_lst		*ft_lst_last(t_lst *lst_a);
t_lst		*ft_lst_new(int number, t_lst *lst_a);
void		ft_add_back(t_lst **lst_a, t_lst *new);

# endif
