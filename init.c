/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:21:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/15 14:45:32 by agoichon         ###   ########.fr       */
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
	if (!map->no || !map->so || !map->we || !map->ea)
	{
		free(map);
		exit(1);
	}
	map->pos = 0;
}

void	init_params(t_map *map)
{
	int	i;
	int	j;
	char *tmp;

	i = 0;
	tmp = NULL;
	j = 0;
	while (map->param_cpy[i] != NULL)
	{	
		if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0 && map->nor == 0)
			map->nor = 1;
		if (ft_strncmp(map->param_cpy[i], "SO", 2) == 0 && map->sou == 0)
			map->sou = 1;
		if (ft_strncmp(map->param_cpy[i], "WE", 2) == 0 && map->wes == 0)
			map->wes = 1;
		if (ft_strncmp(map->param_cpy[i], "EA", 2) == 0 && map->eas == 0)
			map->eas = 1;
		if (ft_strncmp(map->param_cpy[i], "F", 1) == 0 && map->f == 0)
			map->f = 1;
		if (ft_strncmp(map->param_cpy[i], "C", 1) == 0 && map->c == 0)
			map->c = 1;
		i++;
	}
	if (map->nor + map->sou + map->wes + map->eas + map->c + map->f != 6)
	{
		printf("Error params\n");
		free_map(map);
	}
	else
	{
		i = 0;
		while (map->param_cpy[i] != NULL)
		{	
			if (ft_strncmp(map->param_cpy[i], "NO", 2) == 0)
			{
				tmp = megatrim(map, "NO ", i);
				map->no = mlx_load_png(tmp);
				map->no_img = mlx_texture_to_image(map->mlx, map->no);
			}
			if (ft_strncmp(map->param_cpy[i], "SO", 2) == 0)
			{	
				tmp = megatrim(map, "SO ", i);
				map->so = mlx_load_png(tmp);
				map->so_img = mlx_texture_to_image(map->mlx, map->so);
			}
			if (ft_strncmp(map->param_cpy[i], "WE", 2) == 0)
			{
				tmp = megatrim(map, "WE ", i);
				map->we = mlx_load_png(tmp);
				map->we_img = mlx_texture_to_image(map->mlx, map->we);
			}
			if (ft_strncmp(map->param_cpy[i], "EA", 2) == 0)
			{
				tmp = megatrim(map, "EA ", i);
				map->ea = mlx_load_png("./img/ea.png");
				map->ea_img = mlx_texture_to_image(map->mlx, map->ea);
			}
			if (ft_strncmp(map->param_cpy[i], "F", 1) == 0)
			{
				tmp = megatrim(map, "F ", i);
				map->floor = ft_split(tmp, ',');
			}
			if (ft_strncmp(map->param_cpy[i], "C", 1) == 0)
			{
				tmp = megatrim(map, "C ", i);
				map->floor = ft_split(tmp, ',');
			}
			i++;
		}
	}	
}	
