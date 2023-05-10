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

void	copy_map_utils(t_map *map, char *gnl)
{
	int	i;

	map->map_cpy[0] = gnl;
	i = 1;
	while (i < map->line)
	{
		map->map_cpy[i] = get_next_line(map->fd);
		i++;
	}
	map->map_cpy[i] = NULL;
}	

void	copy_map(t_map *map, char **argv)
{
	int		i;
	int		j;
	int		counter;
	char	*gnl;

	line_counter(map);
	map->map_cpy = ft_calloc((map->line + 1), sizeof(char *));
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	gnl = get_next_line(map->fd);
	while (gnl != NULL && ft_strncmp(gnl, "1", 1) != 0)
	{
		j = 0;
		while (gnl[j] == ' ' || gnl[j] == '\t')
			j++;
		if ((ft_strncmp(&gnl[j], "1", 1) == 0
				|| ft_strncmp(&gnl[j], "0", 1) == 0)
			&& gnl[j] != '\0')
			break ;
		free (gnl);
		gnl = get_next_line(map->fd);
	}
	copy_map_utils(map, gnl);
}	

void	open_and_copy(char **argv, t_map *map)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(argv[1]) - 1;
	if (argv[1][len] != 'b'
		|| argv[1][len - 1] != 'u'
		|| argv[1][len - 2] != 'c'
		|| argv[1][len - 3] != '.')
	{
		printf("Please enter a valid map\n");
		printf("Example map.cub\n");
		free_map(map);
		exit (1);
	}
	map->line = 1;
	map->fd = open(argv[1], O_RDONLY);
	copy_map(map, argv);
	check_map(map);
	close(map->fd);
}

static int	check_wall_connection(char **map, int i, int i_next)
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

int	check_connect(t_map *the_map, int j, int i)
{
	int		idx;
	char	**map;

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
