/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/20 08:40:10 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	check_params(t_map *map, char **argv)
{
	int	i;
	int	tmp;

	map->fd = open(argv[1], O_RDONLY);
	tmp = map->line;
	map->line = 0;
	line_counter(map);
	close(map->fd);
	map->param_cpy = malloc(sizeof(char *) * (map->line - tmp) + 1);
	i = 0;
	map->fd = open(argv[1], O_RDONLY);
	while (i < (map->line - tmp) - 2)
	{	
		map->param_cpy[i] = get_next_line(map->fd);
		i++;
	}
	map->param_cpy[i] = NULL;
	close(map->fd);
	init_params(map);
}

void	load_texture(t_map *map, char *str, int i)
{
	char	*tmp;

	tmp = megatrim(map, str, i);
	map->no = mlx_load_png(tmp);
	free(tmp);
	map->no_img = mlx_texture_to_image(map->mlx, map->no);
}

void	load_color(t_map *map, char *str, int i)
{
	char	*tmp;
	char	**split;

	tmp = megatrim(map, str, i);
	split = ft_split(tmp, ',');
	free(tmp);
	tmp = triple_strjoin(split[0], split[1], split[2]);
	if (ft_atol_check(tmp) == 0)
		map->f = ft_atol(tmp);
	free(tmp);
	free_split(split);
}	
