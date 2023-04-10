/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:21:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/10 16:01:00 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	init_struct(t_map *map)
{
	map->floor = NULL;
	map->ceiling = NULL;
	map->no = malloc(sizeof(t_image) * 1);
	map->so = malloc(sizeof(t_image) * 1);
	map->we = malloc(sizeof(t_image) * 1);
	map->ea = malloc(sizeof(t_image) * 1);
	if (!map->no || !map->so || !map->we || !map->ea)
	{
		free(map);
		exit(1);
	}
}

void	line_counter(t_map *map)
{
	char	*ret;

	ret = get_next_line(map->fd);
	if (ret == 0)
	{
		printf("Error gnl\n");
		free(map);
		exit(1);
	}
	map->len_map = ft_strlen(ret);
	while (ret != NULL)
	{
		free(ret);
		map->line++;
		ret = get_next_line(map->fd);
		if (ret == NULL)
			free(ret);
	}
}

void	open_and_copy(char **argv, t_map *map)
{
	int		i;
	int		len;
	char	*gnl;

	i = 0;
	len = ft_strlen(argv[1]) - 1;
	if (argv[1][len] != 'b'
		|| argv[1][len - 1] != 'u'
		|| argv[1][len - 2] != 'c'
		|| argv[1][len - 3] != '.')
	{
		printf("Please enter a valid map\n");
		printf("Example map.cub\n");
		free(map);//boucle avec tous a faire
		exit (1);
	}
	map->line = 1;
	map->len_map = 0;
	map->fd = open(argv[1], O_RDONLY);
	gnl = ft_strdup(" ");
	while (gnl != NULL && ft_strncmp(gnl, "1", 1) != 0)
	{
		free (gnl);
		gnl = get_next_line(map->fd);
	}
	line_counter(map);
	printf("line = %d\n", map->line);
	map->map_cpy = malloc(sizeof(char *) * (map->line));
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	gnl = ft_strdup(" ");
	while (gnl != NULL && ft_strncmp(gnl, "1", 1) != 0)
	{
		free (gnl);
		gnl = get_next_line(map->fd);
	}
	while (i < map->line)
		map->map_cpy[i++] = get_next_line(map->fd);
	for (i = 0; i < map->line ; i++)
	{
		printf("%s", map->map_cpy[i]);
	}
	close(map->fd);
}
