/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:31:40 by auferran          #+#    #+#             */
/*   Updated: 2023/03/07 06:46:52 by auferran         ###   ########.fr       */
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
}	t_lst;\
void		ft_putstr(char *str);
void		ft_error(void);
int			check_arg(char **argv);
char		**ft_split(char const *s, char c);
int			ft_strlen(char *str);
int			ft_atoi(const char *s, int *nb);
int			check_doublon(t_lst *lst_a);
void		init_lst(char **argv, t_lst **lst_a);
void		push_swap(char **dest);
void		ft_lst_clear(t_lst **lst);
int			ft_lst_size(t_lst *lst_a);
t_lst		*ft_lst_last(t_lst *lst_a);
t_lst		*ft_lst_new(int number, t_lst **lst_a);
void		ft_add_back(t_lst **lst_a, t_lst *new);
void		ft_add_front(t_lst **lst_a, t_lst *new);
void		sa(t_lst **lst_a);
void		sb(t_lst **lst_b);
void		ss(t_lst **lst_a, t_lst **lst_b);
void		pa(t_lst **lst_a, t_lst **lst_b);
void		pb(t_lst **lst_a, t_lst **lst_b);
void		ra(t_lst **lst_a);
void		rb(t_lst **lst_b);
void		rr(t_lst **lst_a, t_lst **lst_b);
void		rra(t_lst **lst_a);
void		rrb(t_lst **lst_b);
void		rrr(t_lst **lst_a, t_lst **lst_b);
void		sort(t_lst	**lst_a, t_lst **lst_b);
int			is_sort(t_lst *lst);
int			is_r_sort(t_lst *lst);
void print_lst_TEMP(t_lst *lst_a);

# endif
