/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:46:21 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 15:00:04 by agoichon         ###   ########.fr       */
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

void	b_null(t_map *map)
{
	map->map_cpy = NULL;
	map->param_cpy = NULL;
	map->mlx = NULL;
	map->frame = NULL;
	map->tex = NULL;
}

void	destroy_the_mlx(t_mlx *mlx, t_img *frame, t_img **tex)
{
	int	z;

	z = -1;
	if(frame != NULL)
		mlx_destroy_image(mlx->display, frame->img);
	if (tex != NULL)
	{
		while (++z < 4)
		{
			if (tex[z]->img != NULL)
				mlx_destroy_image(mlx->display, tex[z]->img);
		}
	}
	if (mlx != NULL)
	{	
		mlx_loop_end(mlx->display);
		mlx_destroy_window(mlx->display, mlx->win);
		mlx_destroy_display(mlx->display);
		free (mlx->display);
		free (mlx);
	}
}

void	error_msg(t_map *map)
{
	printf("Error\n");
	end_game(map);
	exit(1);
}	
