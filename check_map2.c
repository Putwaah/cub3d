/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:53:34 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 13:59:13 by agoichon         ###   ########.fr       */
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
		if (ft_strncmp(&gnl[j], "11", 2) == 0)
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

int	check_first_line(t_map *map, int *j)
{
	if (map->map_cpy[0][*j] != '1' && map->map_cpy[0][*j] != ' ')
		return (1);
	while (map->map_cpy[0][*j] == ' ')
	{
		if (map->map_cpy[1][*j] == 0)
			return (1);
		j += 1;
	}
	return (0);
}	

int	check_first_line_bis(t_map *map, int *i, int *j)
{
	while (map->map_cpy[*i] && *i == 0)
	{
		if (map->map_cpy[0][*j] == '0')
			return (1);
		while (map->map_cpy[0][*j] &&
			(map->map_cpy[0][*j] == '1' || map->map_cpy[0][*j] == ' '))
		{
			if (map->map_cpy[0][*j] == ' ' &&
				map->map_cpy[1][*j] != '1' && map->map_cpy[1][*j] != ' ')
				return (1);
			*j += 1;
		}
		if (map->map_cpy[0][*j] == '\n')
				*i = 1;
	}
	return (0);
}	
