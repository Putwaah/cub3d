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
	int		key_release;
}	t_player;

typedef struct s_map
{
	unsigned int	floor;
	unsigned int	ceiling;
	int				f;
	int				c;
	int				nor;
	int				sou;
	int				wes;
	int				eas;
	int				fd;
	int				pos;
	int				line;
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

/*init.c*/
void			init_struct(t_map *map);
void			init_params(t_map *map);
void			init_the_mlx(t_map *map);

/*init2.c*/
void			init_dir(char dir, t_player *player);
t_player		*init_player_data(char **map, int x, int y);

/*utils.c*/
void			free_map(t_map *map);	
void			line_counter(t_map *map);
char			*megatrim(t_map *map, const char *id, int i);
void			free_split(char **str);
void			end_game(t_map *map);

/*utils2.c*/
void			destroy_the_mlx(t_mlx *mlx, t_img *frame, t_img **tex);
void			b_null(t_map *map);
void			error_msg(t_map *map);
void			clear_frame(t_img *frame);
void			count_virgule(t_map *map, char *colors);

/*check_map.c*/
void			check_map(t_map *map);

/*check_map2.c*/
void			copy_map(t_map *map, char **argv);
void			copy_map_utils(t_map *map, char *gnl);
void			open_and_copy(char **argv, t_map *map);
int				check_first_line(t_map *map, int *j);
int				check_first_line_bis(t_map *map, int *i, int *j);

/*check_params.c*/
void			check_params(t_map *map, char **argv);
void			load_texture(t_map *map, char *str, int i, int dir);
void			load_color(t_map *map, char *str, int i);

/*handle.c*/
void			move_forward(t_map *map, t_player *player);
void			move_backward(t_map *map, t_player *player);
void			move_left(t_map	*map, t_player	*player);
void			move_right(t_map *map, t_player *player);
void			move_view_right(t_map *map, t_player *player);

/*handle2.c*/
void			move_view_left(t_map *map, t_player *player);
int				press_key(int key, void *param);
int				press_key(int key, void *param);
int				release_key(int key, void *param);
int				end_game_cross(void *param);

/*ray_K_string.c*/
void			set_pixel(t_img *frame, int x, int y, unsigned int color);
unsigned int	get_pixel(t_img *tex, int x, int y);
void			calc_step(t_rayksting *data, t_player *player);
void			rayksting_init(t_player *player, t_rayksting *data, int x);
void			dda(t_rayksting *data, char **map);

/*ray_K_string2.c*/
void			calc_draw_params(t_rayksting *data, t_player *player);
void			draw_roof(t_map *map, int draw_start, int *y, int x);
void			draw_floor(t_map *map, int *y, int x);
void			draw(t_rayksting *data, t_map *map, t_player *player, int x);
void			ray_k_string(t_map *map, t_player *player);

#endif
