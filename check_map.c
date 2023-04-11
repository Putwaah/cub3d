/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:08:09 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/11 14:56:11 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void	check_map(t_map *map)
{
	int	i;
	int j;
	int	len;

	j = 0;
	if (map->map_cpy[0][j] != '1' && map->map_cpy[0][j] != ' '
		&& map->map_cpy[0][j] != '\t')
	{
		printf("Map Error\n");
		free_map(map);
		exit(1);
	}
	while (map->map_cpy[0][j] == ' ' || map->map_cpy[0][j] == '\t')
		j++;
	while (map->map_cpy[0][j] != '\n' && map->map_cpy[0][j] == '1')
	{
		if (map->map_cpy[0][j] != '1')
		{
			printf("Map Error\n");
			free_map(map);
			exit(1);
		}	
		j++;
	}
	i = 1;
	while (i < map->line - 1)
	{
		j = 0;
		while (map->map_cpy[i][j] != '\n')
		{	
			len = ft_strlen(map->map_cpy[i]) - 2;
			while (map->map_cpy[i][j] == ' ' || map->map_cpy[i][j] == '\t')
				j++;
			if (map->map_cpy[i][j] != '1' || map->map_cpy[i][len] != '1')
			{
				printf("Map Error\n");
				free_map(map);
				exit(1);
			}
			while (j < len)
			{
				if (map->map_cpy[i][j] != '0' && map->map_cpy[i][j] != '1' && map->map_cpy[i][j] != 'N')
				{
					printf("Map Error\n");
					free_map(map);
					exit(1);
				}
				if (map->map_cpy[i][j] == 'N' && map->pos != 1)
					map->pos = 1;
				else if (map->map_cpy[i][j] == 'N' && map->pos == 1)
				{
					printf("va te faire enculer c'est solo\n");
					free_map(map);
					exit(1);
				}
				j++;
			}
			j++;
		}
		i++;
	}
	j = 0;
	while (map->map_cpy[i][j] && map->map_cpy[i][j] == '1')
	{
		if (map->map_cpy[i][j] != '1')
		{
			printf("Map Error\n");
			free_map(map);
			exit(1);
		}	
		j++;
	}
	if (map->pos == 0)
	{
		printf("Error No player\n");
		free_map(map);
		exit(1);
	}	
}

int	copy_map_utils(t_map *map)
{
	char	*gnl;
	int		j;
	int		counter;

	gnl = ft_strdup(" ");
	counter = 0;
	while (gnl != NULL)
	{
		j = 0;
		while (gnl[j])
		{
			while (gnl[j] == ' ' || gnl[j] == '\t')
				j++;
			if (gnl[j] != '1')
				break ;
			else
			{
				while (gnl[j] == '1' && gnl[j] != '\n')
					j++;
				if (gnl[j] == '\n')
					return (counter);
				if (gnl[j] != '1')
				{
					printf("Error 1er ligne\n");
					free_map(map);
					exit(1);
				}	
			}
		}	
		free (gnl);
		gnl = get_next_line(map->fd);
		counter++;
	}
	return (counter);
}

void	copy_map(t_map *map, char **argv)
{
	int		i;
	int		j;
	int		counter;
	char	*gnl;

	counter = copy_map_utils(map) - 1;
	line_counter(map);
	map->map_cpy = malloc(sizeof(char *) * (map->line) + 1);
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	gnl = get_next_line(map->fd);
	while (gnl != NULL && ft_strncmp(gnl, "11", 2) != 0)
	{
		j = 0;
		while (gnl[j] == ' ' || gnl[j] == '\t')
			j++;
		if (ft_strncmp(&gnl[j], "11", 2) == 0)
			break ;
		free (gnl);
		gnl = get_next_line(map->fd);
	}
	map->map_cpy[0] = gnl;
	i = 1;
	while (i < map->line)
		map->map_cpy[i++] = get_next_line(map->fd);
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
	map->len_map = 0;
	map->fd = open(argv[1], O_RDONLY);
	copy_map(map, argv);
	check_map(map);
	close(map->fd);
}
