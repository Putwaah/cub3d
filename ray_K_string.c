/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_K_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:37 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 14:55:45 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pixel(t_img *frame, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = frame->addr + (y * frame->line_len + x * (frame->bpp / 8));
	if (frame->bpp == 32)
		*(int *)pixel = color;
	else if (frame->bpp == 24)
	{
		*(pixel + 2) = (color >> 16) & 0xFF;
		*(pixel + 1) = (color >> 8) & 0xFF;
		*(pixel) = color & 0xFF;
	}
}

unsigned int	get_pixel(t_img *tex, int x, int y)
{
	char	*rtn;

	rtn = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)rtn);
}

void	calc_step(t_rayKsting *data, t_player *player)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (player->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - player->pos_x)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (player->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - player->pos_y)
			* data->delta_dist_y;
	}
}

void	rayKsting_init(t_player *player, t_rayKsting *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	data->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	data->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	data->map_x = (int)player->pos_x;
	data->map_y = (int)player->pos_y;
	if (data->ray_dir_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->ray_dir_y);
	calc_step(data, player);
}

void	dda(t_rayKsting *data, char **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (map[data->map_x][data->map_y] == '1')
			hit = 1;
	}
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->line_height = (HEIGHT / data->perp_wall_dist);
}
