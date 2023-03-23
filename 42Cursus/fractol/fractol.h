/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:23:05 by auferran          #+#    #+#             */
/*   Updated: 2023/03/23 03:30:56 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <stddef.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	error(int nb);
int		check_arg(char **argv);
void	fractol(int nb);
void	create_win_img(void **mlx, void **mlx_win, t_data *img);
void	manage_pixel(void *mlx, void *mlx_win, t_data *img);

# endif
