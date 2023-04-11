/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:21:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/11 15:51:27 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "minilibx-linux/include/MLX42/MLX42.h"

void	init_struct(t_map *map)
{
	map->floor = NULL;
	map->ceiling = NULL;
	map->no = malloc(sizeof(t_image) * 1);
	map->so = malloc(sizeof(t_image) * 1);
	map->we = malloc(sizeof(t_image) * 1);
	map->ea = malloc(sizeof(t_image) * 1);
	if (!map->no || !map->so || !map->we || !map->ea)
	{
		free(map);
		exit(1);
	}
	map->pos = 0;
}

void	init_map(t_map *map)
{
	map->mlx = mlx_init(500, 500, "Cub3d", true);
	if (map->mlx == NULL)
		exit(1);
	map->no->img = mlx_load_png("./img/no.png");
	map->so->img = mlx_load_png("./img/so.png");
	map->ea->img = mlx_load_png("./img/ea.png");
	map->we->img = mlx_load_png("./img/we.png");
}	

