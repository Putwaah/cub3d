/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:59:59 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 16:22:30 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define SPEED 0.2
# define ROT_SPEED 0.1

typedef struct s_mlx
{
	void	*display;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_rayksting
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_x;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				pitch;
	unsigned int	color;
}	t_rayksting;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	unsigned int	floor;
	unsigned int	ceiling;
	char			**map_cpy;
	char			**param_cpy;
	t_mlx			*mlx;
	t_img			**tex;
	t_img			*frame;
}		t_map;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
}			t_game;

//init.c

t_player	*init_player_data(char **map, int x, int y);

//raycasting.c
void	ray_k_string(t_map *map, t_player *player);
void	set_pixel(t_img *frame, int x, int y, unsigned int color);

//raycasting_2.c
void	draw(t_rayksting *data, t_map *map, t_player *player, int x);

//utils.c
int	map_start(t_map *map, char **args);
void	end_game(t_map *map);

//utils_2.c
void	exit_error(t_map *map, char *err_msg);

//check_map.c
void	check_map(t_map *map);

void	check_the_line(t_map *map, int z);
void	connect_end_under(t_map *map, int line, int last, int last_under);
void	connect_end_above(t_map *map, int line, int last, int last_above);
void	connect_start_under(t_map *map, int line, int start, int start_under);
void	connect_start_above(t_map *map, int line, int start, int start_above);

//check_map_utils.c
int		max_line_len(char **map);
int		tab_count(char **to_count);
int		*init_tab(int max_line_len);
int		check_tab(int *check, int max);
int		char_check(char to_check);

int	check_params(t_map *map, char *line, int start, int *check);
char **copy_file(t_map *map, char *file);
void	count_virgule(t_map *map, char *colors);

int	press_key(int key, void *param);
int	release_key(int key, void *param);
int	end_game_cross(void *param);
void	move_view_right(t_map *map, t_player *player);
void	move_view_left(t_map *map, t_player *player);
void	b_null(t_map *map);
void	init_params(t_map *map);

#endif