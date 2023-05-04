/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:08:09 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 13:56:34 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_middle_ter(t_map *map, int *i, int *j)
{
	if (map->map_cpy[*i][*j] != '0' && map->map_cpy[*i][*j] != ' '
		&& map->map_cpy[*i][*j] != '1'
		&& (map->map_cpy[*i][*j] != 'N'
		&& map->map_cpy[*i][*j] != 'S'
		&& map->map_cpy[*i][*j] != 'E'
		&& map->map_cpy[*i][*j] != 'W'))
		return (1);
	return (0);
}	

static int	check_middle_bis(t_map *map, int *i, int *j, int *len)
{
	while (*j < *len)
	{
		if (check_middle_ter(map, i, j) == 1)
			return (1);
		if (map->map_cpy[*i][*j] == ' ' &&
			(map->map_cpy[*i - 1][*j] == '0' ||
			map->map_cpy[*i + 1][*j] == '0' ||
			map->map_cpy[*i][*j - 1] == '0' ||
			map->map_cpy[*i][*j + 1] == '0'))
			return (1);
		if ((map->map_cpy[*i][*j] == 'N'
			|| map->map_cpy[*i][*j] == 'S'
		|| map->map_cpy[*i][*j] == 'E'
		|| map->map_cpy[*i][*j] == 'W')
		&& map->pos != 1)
			map->pos = 1;
		else if ((map->map_cpy[*i][*j] == 'N'
			|| map->map_cpy[*i][*j] == 'S'
		|| map->map_cpy[*i][*j] == 'E'
		|| map->map_cpy[*i][*j] == 'W')
		&& map->pos == 1)
			return (1);
	*j += 1;
	}
	return (0);
}	

static int	check_middle(t_map *map, int *i, int *j)
{
	int	len;

	while (*i < map->line - 1)
	{
		*j = 0;
		while (map->map_cpy[*i][*j] != '\n')
		{	
			len = ft_strlen(map->map_cpy[*i]) - 2;
			while (map->map_cpy[*i][*j] == ' ')
				*j += 1;
			if (map->map_cpy[*i][*j] != '1' || map->map_cpy[*i][len] != '1')
				return (1);
			if (check_middle_bis(map, i, j, &len) == 1)
				return (1);
			*j += 1;
		}
		*i += 1;
	}
	return (0);
}	

static int	check_last_line(t_map *map, int *i, int *j)
{
	while (map->map_cpy[*i][*j])
	{
		if (map->map_cpy[*i][*j] != '1')
		{
			if (map->map_cpy[*i][*j] == ' ' && (map->map_cpy[*i - 1][*j] == '1'
				|| (map->map_cpy[*i - 1][*j] == ' ')))
				*j += 1;
			if (map->map_cpy[*i][*j] == ' ' && map->map_cpy[*i - 1][*j] == '0')
				return (1);
		}	
		*j += 1;
	}
	return (0);
}	

void	check_map(t_map *map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	if (check_first_line(map, &j) == 1)
		error_msg(map);
	i = 0;
	if (check_first_line_bis(map, &i, &j) == 1)
		error_msg(map);
	map->line = 1;
	while (map->map_cpy[i])
	{
		map->line++;
		i++;
	}
	i = 1;
	if (check_middle(map, &i, &j) == 1)
		error_msg(map);
	j = 0;
	if (check_last_line(map, &i, &j) == 1)
		error_msg(map);
	if (map->pos == 0)
		error_msg(map);
}
