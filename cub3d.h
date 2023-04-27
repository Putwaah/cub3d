/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:59:59 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/20 08:47:34 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../cub3d/libft/libft.h"
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
#include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define SPEED 0.2
# define ROT_SPEED 0.1

typedef struct s_mlx
{
    void    *display;
    void    *win;
}          t_mlx;

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;  
}           t_img;

typedef struct s_rayKsting
{
	//double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double wall_x;
	int	map_x;
	int	map_y;
	int	step_x;
	int	step_y;
	int	hit;
	int	side;
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	tex_num;
	int	tex_x;
	int	tex_y;
	int 	pitch;
	unsigned int	color;
}	t_rayKsting;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		key_release;
}	t_player;

typedef struct s_map
{
	char	*floor;
	int		f;
	char	*ceiling;
	int		c;
	int		nor;
	int		sou;
	int		wes;
	int		eas;
	int		fd;
	int		pos;
	int		line;
	char	**map_cpy;
	char	**param_cpy;
	t_mlx	*mlx;
	t_img	**tex;
	t_img	*frame;
	//t_player	*player;
}		t_map;

typedef struct s_game
{
	t_map 		*map;
	t_player	*player;
}			t_game;

/*init.c*/
void	init_struct(t_map *map);
void	init_params(t_map *map);

/*utils.c*/
void	free_map(t_map *map);	
void	line_counter(t_map *map);
int		ft_tablen(char **str);
char	*megatrim(t_map *map, const char *id, int i);
void	free_split(char **str);

/*check_map.c*/
void	copy_map(t_map *map, char **argv);
void	open_and_copy(char **argv, t_map *map);
void	check_map(t_map *map);

/*check_params.c*/
void	check_params(t_map *map, char **argv);
void	load_texture(t_map *map, char *str, int i, int dir);
void	load_color(t_map *map, char *str, int i);
/*handle.c*/
int	press_key(int key, void *param);
int	release_key(int key, void *param);

void	destroy_the_mlx(t_mlx *mlx, t_img *frame, t_img **tex);
void	b_null(t_map *map);
void	end_game(t_map *map); 
void	init_the_mlx(t_map *map);
t_player	*init_player_data(char **map);
void    ray_k_string(t_map *map, t_player *player);

#endif
