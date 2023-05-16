/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:08:09 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/16 09:42:35 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_left_n_right(t_map *map)
{
	int	z;

	z = 1;
	while (map->map_cpy[z + 1])
	{	
		check_the_line(map, z);
		z++;
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
				exit_error(map, "map error");
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
			if ((map->map_cpy[z][y] == '0' && check[y] != 1)
					|| char_check(map->map_cpy[z][y]) != 1)
			{	
				free (check);
				exit_error(map, "map error");
			}
			y++;
		}
		y = 0;
		z--;
	}
	free (check);
}

static void	basic_check(t_map *map)
{
	int	player;
	int	z;
	int	y;

	player = 0;
	z = 0;
	y = 0;
	if (tab_count(map->map_cpy) <= 2)
		exit_error(map, "map problem");
	while (map->map_cpy[z])
	{
		while (map->map_cpy[z][y])
		{
			if (map->map_cpy[z][y] == 'N' || map->map_cpy[z][y] == 'W'
				|| map->map_cpy[z][y] == 'E' || map->map_cpy[z][y] == 'S')
				player++;
			if (char_check(map->map_cpy[z][y]) != 1)
				exit_error(map, "unauthorized character");
			y++;
		}
		y = 0;
		z++;
	}
	if (player != 1)
		exit_error(map, "one player por favor");
}

void	check_map(t_map *map)
{
	basic_check(map);
	check_from_top(map);
	check_from_bot(map);
	check_left_n_right(map);
}
