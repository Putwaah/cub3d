/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/15 14:23:18 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	check_params(t_map *map, char **argv)
{
	int i;
	int	tmp;

	map->fd = open(argv[1], O_RDONLY);
	tmp = map->line;
	map->line = 0;
	line_counter(map);
	close(map->fd);
	map->param_cpy = malloc(sizeof(char *) * (map->line - tmp) + 1);
	i = 0;
	map->fd = open(argv[1], O_RDONLY);
	while (i < (map->line - tmp) - 1)
	{	
		map->param_cpy[i] = get_next_line(map->fd);
		i++;
	}
	map->param_cpy[i] = NULL;
	close(map->fd);
	init_params(map);
}	
