/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:45:56 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/16 09:45:59 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_params(t_map *map, char *line, int start, int *check)
{
	int	param;

	if (ft_strncmp(&line[start], "NO ", 3) == 0)
		param = 0;
	else if (ft_strncmp(&line[start], "SO ", 3) == 0)
		param = 1;
	else if (ft_strncmp(&line[start], "WE ", 3) == 0)
		param = 2;
	else if (ft_strncmp(&line[start], "EA ", 3) == 0)
		param = 3;
	else if (ft_strncmp(&line[start], "F ", 2) == 0)
		param = 4;
	else if (ft_strncmp(&line[start], "C ", 2) == 0)
		param = 5;
	else
	{
		if (line[start] != '\n' && line[start] != '\0')
			return (0);
		return (1);
	}
	if (check[param] == 1)
		return (0);
	map->param_cpy[param] = ft_strdup(line);
	check[param] = 1;
	return (1);
}

static char	**malloc_file_size(t_map *map, char *file)
{
	char	*gnl;
	char	**copy;
	int		len;
	int		fd;

	len = 1;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit_error(map, "problem accessing the file");
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		if (len == 1)
			free (gnl);
		gnl = get_next_line(fd);
		len++;
		if (gnl != NULL)
			free (gnl);
	}
	close (fd);
	if (len < 2)
		exit_error(map, "problemo");
	copy = ft_calloc(len + 1, sizeof(char *));
	return (copy);
}

char	**copy_file(t_map *map, char *file)
{
	char	**copy;
	char	*gnl;
	int		fd;
	int		z;

	z = 0;
	gnl = NULL;
	copy = malloc_file_size(map, file);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit_error(map, "problem accessing the file");
	while (gnl != NULL || z <= 0)
	{	
		gnl = get_next_line(fd);
		if (gnl != NULL)
		{
			copy[z] = ft_strdup(gnl);
			free (gnl);
		}
		z++;
	}
	close (fd);
	return (copy);
}
