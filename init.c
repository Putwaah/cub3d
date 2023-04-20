/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:21:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/19 16:18:12 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include "minilibx-linux/include/MLX42/MLX42.h"
#include <stdlib.h>

void	init_struct(t_map *map)
{
	map->floor = NULL;
	map->f = 0;
	map->ceiling = NULL;
	map->c = 0;
	map->no = malloc(sizeof(mlx_texture_t) * 1);
	map->no_img = malloc(sizeof(mlx_image_t) * 1);
	map->nor = 0;
	map->so = malloc(sizeof(mlx_texture_t) * 1);
	map->so_img = malloc(sizeof(mlx_image_t) * 1);
	map->sou = 0;
	map->we = malloc(sizeof(mlx_texture_t) * 1);
	map->we_img = malloc(sizeof(mlx_image_t) * 1);
	map->wes = 0;
	map->ea = malloc(sizeof(mlx_texture_t) * 1);
	map->ea_img = malloc(sizeof(mlx_image_t) * 1);
	map->eas = 0;
	if (!map->no || !map->so || !map->we || !map->ea
		|| !map->no_img || !map->so_img || !map->we_img || !map->ea_img)
	{
		free(map);
		exit(1);
	}
	map->pos = 0;
}

void	init_params_bis(t_map *map, int i)
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

void	init_params_ter(t_map *map, int i)
{
	if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0)
		load_texture(map, "NO ", i);
	if (ft_strncmp(map->param_cpy[i], "SO", 2) == 0)
		load_texture(map, "SO ", i);
	if (ft_strncmp(map->param_cpy[i], "WE", 2) == 0)
		load_texture(map, "WE ", i);
	if (ft_strncmp(map->param_cpy[i], "EA", 2) == 0)
		load_texture(map, "EA ", i);
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
	else
	{
		i = 0;
		while (map->param_cpy[i] != NULL)
		{
			init_params_ter(map, i);
			i++;
		}	
	}
}	
