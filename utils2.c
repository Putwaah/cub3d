/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:19 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 15:35:59 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	error_msg(t_map *map)
{
	printf("Error\n");
	end_game(map);
	exit(1);
}
