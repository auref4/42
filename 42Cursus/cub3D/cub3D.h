/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:02:10 by auferran          #+#    #+#             */
/*   Updated: 2023/12/08 19:01:19 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx_linux/mlx.h"
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>


#define POV 60
#define	FISHBOWL -30
#define PLAYER_HEIGHT 32
#define SIZE_CUBE 64
#define	WIDTH 1280
#define HEIGHT_PLANE 720
#define NORTH 0x0000FF
#define SOUTH 0xFF0000
#define EAST 0x008000
#define WEST 0x7F00FF
#define FLOOR 0x70726E
#define SKY 0x2A303D

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

typedef struct s_map
{
	char	**map;
	double	pixel_x_player;
	double	pixel_y_player;
	double	axe_player;
	double	projection_plane;
	double	distance_wall;
	double	between_rays;
}			t_map;

typedef struct s_calcul
{
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;
	int		grid_x;
	int		grid_y;
	double	ya;
	double	xa;
}			t_calcul;

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
}				t_key;

typedef struct	s_mlx
{
	int		*image;
	void	*mlx;
	void	*mlx_win;
	void	*s_image;
	int		win_x;
	int		win_y;
}				t_mlx;
typedef struct s_env
{
	t_mlx		mlx;
	t_map		map;
	t_calcul	h;
	t_calcul	v;
}			t_env;

typedef struct s_lst
{
	char			*data;
	struct s_lst	*next;
}					t_lst;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_memset(void *pointer, int value, size_t count);
char	*get_next_line(int fd);

int		get_map(t_map *map, char *map_title);

int		add_to_list(char *line, t_lst **lst);
void	del_one(t_lst **lst, t_lst *node);
void	lst_clear(t_lst **lst);
int		lst_size(t_lst *lst);
char	**lst_to_tab(t_lst *lst);

void	get_pos_player(t_map *map);

void	get_next_wall(t_env *env);

void	find_wall_h(t_env *env, double a_p);
void	find_wall_v(t_env *env, double a_p);

int		its_wall(char **map, int grid_y, int grid_x);
double	calcul_projection_plane(void);
double	calcul_a_p(double axe_player);
void	recalcul_a_p(double *a_p, double between_rays);
double	calcul_distance(t_env *env, int *x, int *y);
void	remove_fishbowl(double *distance, double i);

int		init_mlx(t_mlx *mlx);

#endif
