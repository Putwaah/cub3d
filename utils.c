/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:46:21 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/16 09:44:52 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_map *map)
{
	int	z;

	z = 0;
	if (map->map_cpy != NULL)
		free_loop(map->map_cpy);
	if (map->param_cpy != NULL)
	{
		while (z < 6)
		{
			free(map->param_cpy[z]);
			z++;
		}
		free (map->param_cpy);
	}
	z = -1;
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

static void	destroy_the_mlx(t_mlx *mlx, t_img *frame, t_img **tex)
{
	int	z;

	z = -1;
	if (frame != NULL)
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

void	end_game(t_map *map)
{
	destroy_the_mlx(map->mlx, map->frame, map->tex);
	free_map(map);
	exit (69);
}

int	map_start(t_map *map, char **args)
{
	int	z;
	int	y;

	y = 0;
	z = 0;
	while (args[z])
	{
		while (args[z][y] == ' ')
			y++;
		if (args[z][y] == '0' || args[z][y] == '1')
			return (z);
		y = 0;
		z++;
	}
	free_loop(args);
	exit_error(map, "no map found");
	return (0);
}
