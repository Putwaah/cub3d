/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:46:21 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/12 11:10:58 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

void	free_map(t_map *map)
{
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	free(map->map_cpy);
	free(map);
}	

int		ft_tablen(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{	
		while (str[i][j])
			j++;	
		i++;
	}
	return (i);
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
