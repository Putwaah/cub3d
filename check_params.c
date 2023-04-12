/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/12 11:14:44 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	check_params_utils(t_map *map)
{
	int	i;
	int	len;
	int	check;

	i = 0;
	len = ft_tablen(map->param_cpy);
	check = 0;
	while (i <= len - 1)
	{
		if (*map->param_cpy[i] == '\n')
			i++;
		else if (ft_strncmp(map->param_cpy[i], "NO ", 3) == 0
			|| ft_strncmp(map->param_cpy[i], "SO ", 3) == 0
			|| ft_strncmp(map->param_cpy[i], "WE ", 3) == 0
			|| ft_strncmp(map->param_cpy[i], "EA ", 3) == 0
			|| ft_strncmp(map->param_cpy[i], "F ", 2) == 0
			|| ft_strncmp(map->param_cpy[i], "C ", 2) == 0)
		{
			check++;
			i++;
		}
		else
			break ;
	}
	if (check != 6)
	{
		printf("Error params\n");
		free_map(map);
		exit (1);
	}	
}	

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
	while (i < (map->line - tmp))
	{	
		map->param_cpy[i] = get_next_line(map->fd);
		i++;
	}
	check_params_utils(map);
	for (i = 0; i < (map->line - tmp); i++)
	{
		printf("param[%d] %s", i, map->param_cpy[i]);
	}
	for (i = 0; i <  tmp; i++)
	{
		printf("map[%d] %s", i, map->map_cpy[i]);
	}
	close(map->fd);
}	
