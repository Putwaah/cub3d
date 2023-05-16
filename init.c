/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:21:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/16 09:49:35 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	init_struct(t_map *map)
{
	b_null(map);
	map->param_cpy = ft_calloc(7, sizeof(char *));
}*/

static void	north_south_init(char dir, t_player *player)
{
	if (dir == 'N')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (dir == 'S')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	init_dir(char dir, t_player *player)
{
	if (dir == 'N' || dir == 'S')
	{
		north_south_init(dir, player);
	}
	else if (dir == 'E')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (dir == 'W')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

t_player	*init_player_data(char **map, int x, int y)
{
	t_player	*player;
	static int	found = 0;

	player = malloc(sizeof(t_player));
	while (map[x] && found == 0)
	{
		while (map[x][y] && found == 0)
		{
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'E' || map[x][y] == 'W')
			{	
				init_dir(map[x][y], player);
				found = 1;
				player->pos_x = x + 0.5;
				player->pos_y = y + 0.5;
				map[x][y] = '0';
			}
			y++;
		}
		x++;
		if (found != 1)
			y = 0;
	}
	return (player);
}

void	init_the_mlx(t_map *map)
{
	int		z;

	z = -1;
	map->mlx = malloc(sizeof(t_mlx));
	map->mlx->display = mlx_init();
	if (!map->mlx->display)
	{
		end_game(map);
		exit (69);
	}
	map->frame = malloc(sizeof(t_img));
	map->tex = malloc(4 * sizeof(t_img *));
	while (++z < 4)
		map->tex[z] = malloc(sizeof(t_img));
	z = -1;
	map->mlx->win = mlx_new_window(map->mlx->display, WIDTH, HEIGHT, "CUB3D");
	map->frame->img = mlx_new_image(map->mlx->display, WIDTH, HEIGHT);
	map->frame->addr = mlx_get_data_addr(map->frame->img,
			&map->frame->bpp, &map->frame->line_len,
			&map->frame->endian);
	while (++z < 4)
		map->tex[z]->img = NULL;
}

void	init_params(t_map *map)
{
	int	i;

	i = 0;
	while (map->param_cpy[i] != NULL)
	{
		if (i == 0)
			init_the_mlx(map);
		if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0)
			load_texture(map, "NO ", i, 0);
		else if (ft_strncmp(map->param_cpy[i], "SO", 2) == 0)
			load_texture(map, "SO ", i, 1);
		else if (ft_strncmp(map->param_cpy[i], "WE", 2) == 0)
			load_texture(map, "WE ", i, 2);
		else if (ft_strncmp(map->param_cpy[i], "EA", 2) == 0)
			load_texture(map, "EA ", i, 3);
		else if (ft_strncmp(map->param_cpy[i], "F", 1) == 0)
			load_color(map, "F ", i);
		else if (ft_strncmp(map->param_cpy[i], "C", 1) == 0)
			load_color(map, "C ", i);
		i++;
	}	
}
