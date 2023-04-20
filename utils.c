/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:46:21 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/20 08:42:05 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <stdlib.h>

void	free_map(t_map *map)
{
	free(map->no);
	free(map->no_img);
	free(map->so);
	free(map->so_img);
	free(map->we);
	free(map->we_img);
	free(map->ea);
	free(map->ea_img);
	free(map->map_cpy);
	free(map->param_cpy);
	free(map);
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

	rtn = ft_strtrim(map->param_cpy[i], id);
	rtn = ft_strtrim(rtn, "\n");
	rtn = ft_strtrim(rtn, "\t");
	rtn = ft_strtrim(rtn, " ");
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
