/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:21:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/11 11:12:45 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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



