/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:21:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 15:38:35 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_map *map)
{
	static int	z = -1;

	map->f = 0;
	map->c = 0;
	map->nor = 0;
	map->sou = 0;
	map->wes = 0;
	map->eas = 0;
	b_null(map);
	map->pos = 0;
}

static void	init_params_bis(t_map *map, int i)
{
	if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->nor == 0)
		map->nor = 1;
	else if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->nor == 1)
		map->nor = 2;
	if (ft_strncmp(map->param_cpy[i], "SO", 2) == 0 && map->sou == 0)
		map->sou = 1;
	else if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->sou == 1)
		map->sou = 2;
	if (ft_strncmp(map->param_cpy[i], "WE", 2) == 0 && map->wes == 0)
		map->wes = 1;
	else if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->wes == 1)
		map->wes = 2;
	if (ft_strncmp(map->param_cpy[i], "EA", 2) == 0 && map->eas == 0)
		map->eas = 1;
	else if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->eas == 1)
		map->eas = 2;
	if (ft_strncmp(map->param_cpy[i], "F", 1) == 0 && map->f == 0)
		map->f = 1;
	else if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->f == 1)
		map->f = 2;
	if (ft_strncmp(map->param_cpy[i], "C", 1) == 0 && map->c == 0)
		map->c = 1;
	else if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->f == 1)
		map->f = 2;
}	

static void	init_params_ter(t_map *map, int i)
{
	int	z;

	z = -1;
	if (i == 0)
		init_the_mlx(map);
	if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0)
		load_texture(map, "NO ", i, 0);
	if (ft_strncmp(map->param_cpy[i], "SO", 2) == 0)
		load_texture(map, "SO ", i, 1);
	if (ft_strncmp(map->param_cpy[i], "WE", 2) == 0)
		load_texture(map, "WE ", i, 2);
	if (ft_strncmp(map->param_cpy[i], "EA", 2) == 0)
		load_texture(map, "EA ", i, 3);
	if (ft_strncmp(map->param_cpy[i], "F", 1) == 0)
		load_color(map, "F ", i);
	if (ft_strncmp(map->param_cpy[i], "C", 1) == 0)
		load_color(map, "C ", i);
}	

void	init_params(t_map *map)
{
	int	i;

	i = 0;
	while (map->param_cpy[i] != NULL)
	{
		init_params_bis(map, i);
		i++;
	}
	if (map->nor + map->sou + map->wes + map->eas + map->c + map->f != 6)
	{
		printf("Error params\n");
		free_map(map);
		exit (1);
	}
	i = 0;
	while (map->param_cpy[i] != NULL)
	{
		init_params_ter(map, i);
		i++;
	}	
}

void	init_the_mlx(t_map *map)
{
	t_mlx	*mlx;
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
	map->mlx->win = mlx_new_window(map->mlx->display, WIDTH, HEIGHT, "fnetre");
	map->frame->img = mlx_new_image(map->mlx->display, WIDTH, HEIGHT);
	map->frame->addr = mlx_get_data_addr(map->frame->img,
			&map->frame->bpp, &map->frame->line_len,
			&map->frame->endian);
	while (++z < 4)
		map->tex[z]->img = NULL;
}
