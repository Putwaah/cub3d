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

/*static int	check_middle_ter(t_map *map, int *i, int *j)
{
	if (map->map_cpy[*i][*j] != '0' && map->map_cpy[*i][*j] != ' '
		&& map->map_cpy[*i][*j] != '1'
		&& (map->map_cpy[*i][*j] != 'N'
		&& map->map_cpy[*i][*j] != 'S'
		&& map->map_cpy[*i][*j] != 'E'
		&& map->map_cpy[*i][*j] != 'W'))
		return (1);
	return (0);
}*/	

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

int check_wall_connection(char **map, int i, int i_next)
{
	int	last;
	int	last_upper;

	last = ft_strlen(map[i]) - 2;
	last_upper = ft_strlen(map[i_next]) - 2;
	if (last < last_upper)
	{
		while (last_upper >= last + 1)
		{
			if (map[i_next][last_upper] == '0')
				return (0);
			last_upper--;
		}
	}
	else
	{
		while (last >= last_upper + 1)
		{
			if (map[i][last] == '0')
				return (0);
			last--;
		}
	}
	return (1);
}

int check_connect(t_map *the_map, int j, int i)
{
	int 	idx;
	char 	**map;

	map = the_map->map_cpy;
	idx = j - 1;
	while (idx >= 0)
	{
		if (map[i - 1][idx] == '0'
			|| map[i + 1][idx] == '0')
			return (0);
		idx--;	
	}
	if (check_wall_connection(map, i, i - 1) != 1
		|| check_wall_connection(map, i, i + 1) != 1)
		return (0);
	return (1);
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

int	max_line_len(char **map)
{
	int	z;
	int max;

	max = 0;
	z = 0;
	while (map[z])
	{
		if (ft_strlen(map[z]) > max)
			max = ft_strlen(map[z]);
		z++;
	}
	return (max);
}

int	*init_tab(int max_line_len)
{
	int	*rtn;
	int	z;

	z = 0;
	rtn = malloc(sizeof(int) * max_line_len);
	while (z < max_line_len)
	{
		rtn[z] = 0;
		z++;
	}
	return (rtn);
}

int	check_tab(int *check, int max)
{
	int	z;

	z = 0;
	while (z < max)
	{
		if (check[z] != 1)
			return (0);
		z++;
	}
	return (1);
}

void	check_from_top(t_map *map)
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
	printf("top good\n");
}

int	char_check(char to_check)
{
	if (to_check != '0' && to_check != '1' && to_check != 'N'
		&& to_check != 'S' && to_check != 'W' && to_check != 'E'
		&& to_check != ' ' && to_check != '\0' && to_check != '\n')
		return (0);
	return (1);
}

void	check_from_bot(t_map *map)
{
	int	*check;
	volatile int	z;
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
				printf("bot no good\n");
				free (check);
				error_msg(map);
			}
			y++;
		}
		y = 0;
		z--;
	}
	printf("bot good\n");
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
