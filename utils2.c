/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:19 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/08 14:35:15 by jtoulous         ###   ########.fr       */
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

void	exit_error(t_map *map, char *err_msg)
{
	printf("%s\n", err_msg);
	end_game(map);
}

void	clear_frame(t_img *frame)
{
	int		x;
	int		y;
	char	*pix;

	x = -1;
	y = -1;
	while (++x < WIDTH)
	{
		while (++y < HEIGHT)
		{
			pix = frame->addr + (y * frame->line_len + x * (frame->bpp / 8));
			if (frame->bpp == 32)
				*(int *)pix = 0;
			else if (frame->bpp == 24)
			{
				*(pix) = 0;
				*(pix + 1) = 0;
				*(pix + 2) = 0;
			}
			y++;
		}
		y = 0;
		x++;
	}
}

void	count_virgule(t_map *map, char *colors)
{
	int	z;
	int	count;

	count = 0;
	z = 0;
	while (colors[z])
	{
		if (colors[z] == ',')
			count++;
		z++;
	}
	if (count != 2)
	{
		free (colors);
		end_game(map);
	}
}