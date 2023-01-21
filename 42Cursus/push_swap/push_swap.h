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

typedef struct s_elmt
{
	int	nb;
	struct s_elmt	*next;
	struct s_elmt	*prev;
}	t_elmt;
int	ft_atoi(const char *s);
//void	push(element **element_a, element **element_b);
//void	swap(element **element_b, element **element_b);
//int	element_size(element *element_a);
void	push_swap(char **argv);
void	ft_error(void);
int	ft_elmt_size(t_elmt *first_a);
t_elmt	*ft_elmt_last(t_elmt *first_a);
t_elmt	*ft_elmt_new(int number);
void	ft_add_back(t_elmt **first_a, t_elmt *new);

# endif
