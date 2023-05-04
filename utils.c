/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:46:21 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 16:24:31 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	int	z;

	z = -1;
	if (map->map_cpy != NULL)
		free_loop(map->map_cpy);
	if (map->param_cpy != NULL)
		free_loop(map->param_cpy);
	if (map->frame != NULL)
		free (map->frame);
	if (map->tex != NULL)
	{
		while (++z < 4)
			free (map->tex[z]);
		free (map->tex);
	}
	free (map);
}	

void	line_counter(t_map *map)
{
	char	*ret;

	ret = get_next_line(map->fd);
	if (ret == 0)
	{
		printf("Error\n");
		free(map);
		exit(1);
	}
	while (ret != NULL)
	{
		free(ret);
		map->line++;
		ret = get_next_line(map->fd);
		if (ret == NULL)
			free(ret);
	}
}

char	*megatrim(t_map *map, const char *id, int i)
{
	char	*rtn;
	char	*tmp;

	tmp = ft_strtrim(map->param_cpy[i], id);
	rtn = ft_strtrim(tmp, "\n");
	free (tmp);
	tmp = ft_strtrim(rtn, "\t");
	free (rtn);
	rtn = ft_strtrim(tmp, " ");
	free (tmp);
	return (rtn);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}	

void	end_game(t_map *map)
{
	destroy_the_mlx(map->mlx, map->frame, map->tex);
	free_map(map);
	exit (69);
}
