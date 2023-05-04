/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:08:09 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 13:51:49 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

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
