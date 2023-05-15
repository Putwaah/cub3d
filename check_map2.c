/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:53:34 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/10 17:32:40 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	connect_start_above(t_map *map, int line, int start, int start_above)
{
	if (start > start_above)
	{
		while (start_above < start - 1)
		{
			if (map->map_cpy[line - 1][start_above] == '0')
				exit_error(map, "map error");
			start_above++;
		}
	}
	else
	{
		while (start < start_above - 1)
		{
			if (map->map_cpy[line][start] == '0')
				exit_error(map, "map error");
			start++;
		}
	}
}

void	connect_start_under(t_map *map, int line, int start, int start_under)
{
	if (start_under < start)
	{
		while (start_under < start - 1)
		{
			if (map->map_cpy[line + 1][start_under] == '0')
				exit_error(map, "map error");
			start_under++;
		}
	}
	else
	{
		while (start < start_under - 1)
		{
			if (map->map_cpy[line][start] == '0')
				exit_error(map, "map error");
			start++;
		}
	}
}

void	connect_end_above(t_map *map, int line, int last, int last_above)
{
	if (last_above > last)
	{
		while (last_above > last + 1)
		{
			if (map->map_cpy[line - 1][last_above] == '0')
				exit_error(map, "map error");
			last_above--;
		}
	}
	else
	{
		while (last > last_above + 1)
		{
			if (map->map_cpy[line][last] == '0')
				exit_error(map, "map error");
			last--;
		}
	}
}

void	connect_end_under(t_map *map, int line, int last, int last_under)
{
	if (last_under > last)
	{
		while (last_under > last + 1)
		{
			if (map->map_cpy[line + 1][last_under] == '0')
				exit_error(map, "map error");
			last_under--;
		}
	}
	else
	{
		while (last > last_under + 1)
		{
			if (map->map_cpy[line][last] == '0')
				exit_error(map, "map error");
			last--;
		}
	}
}