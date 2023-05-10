/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:08:09 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 15:52:03 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_middle_bis(t_map *map, int *i, int *j, int *len)
{
	while (*j < *len)
	{
		if (char_check(map->map_cpy[*i][*j]) != 1)
			return (1);
		if (map->map_cpy[*i][*j] == ' ' &&
			(map->map_cpy[*i - 1][*j] == '0' ||
			map->map_cpy[*i + 1][*j] == '0' ||
			map->map_cpy[*i][*j - 1] == '0' ||
			map->map_cpy[*i][*j + 1] == '0'))
			return (1);
		if (map->map_cpy[*i][*j] == 'N'
			|| map->map_cpy[*i][*j] == 'S'
			|| map->map_cpy[*i][*j] == 'E'
			|| map->map_cpy[*i][*j] == 'W')
		{
			if (map->pos == 1)
				return (1);
			map->pos = 1;
		}
	*j += 1;
	}
	return (0);
}

static void	check_middle(t_map *map, int *i, int *j)
{
	int	len;
	int	first;
	int	last;

	while (*i < tab_count(map->map_cpy) - 1)
	{
		*j = 0;
		while (map->map_cpy[*i][*j] != '\n')
		{	
			len = ft_strlen(map->map_cpy[*i]) - 2;
			while (map->map_cpy[*i][*j] == ' ')
				*j += 1;
			if (map->map_cpy[*i][*j] != '1' || map->map_cpy[*i][len] != '1')
				error_msg(map);;
			first = *j;
			last = len;
			if (check_middle_bis(map, i, j, &len) == 1)
				error_msg(map);;
			*j += 1;
		}
		if (check_connect(map, first, *i) != 1)
			error_msg(map);;
		*i += 1;
	}
}	

static void	check_from_top(t_map *map)
{
	int	*check;
	int	z;
	int	y;

	y = 0;
	z = 0;
	check = init_tab(max_line_len(map->map_cpy));
	while (map->map_cpy[z] && check_tab(check, max_line_len(map->map_cpy)) != 1)
	{
		while (map->map_cpy[z][y])
		{
			if (map->map_cpy[z][y] == '1' && check[y] == 0)
				check[y] = 1;
			if (map->map_cpy[z][y] == '0' && check[y] != 1)
			{	
				free (check);
				error_msg(map);
			}
			y++;
		}
		y = 0;
		z++;
	}
	free (check);
}

static void	check_from_bot(t_map *map)
{
	int	*check;
	int	z;
	int	y;

	y = 0;
	z = tab_count(map->map_cpy) - 1;
	check = init_tab(max_line_len(map->map_cpy));
	while (z > 0 && check_tab(check, max_line_len(map->map_cpy)) != 1)
	{
		while (map->map_cpy[z][y])
		{
			if (map->map_cpy[z][y] == '1' && check[y] == 0)
				check[y] = 1;
			if ((map->map_cpy[z][y] == '0' && check[y] != 1) || char_check(map->map_cpy[z][y]) != 1)
			{	
				free (check);
				error_msg(map);
			}
			y++;
		}
		y = 0;
		z--;
	}
	free (check);
}

void	check_map(t_map *map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	map->line = 1;
	while (map->map_cpy[i])
	{
		map->line++;
		i++;
	}
	i = 1;	
	check_from_top(map);
	check_from_bot(map);
	check_middle(map, &i, &j);
}
