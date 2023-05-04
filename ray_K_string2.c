/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_K_string2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:17 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 14:53:55 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_draw_params(t_rayKsting *data, t_player *player)
{
	data->pitch = 100;
	data->draw_start = -data->line_height / 2 + HEIGHT / 2 + data->pitch;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2 + data->pitch;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT - 1;
	data->tex_num = 0;
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_num = 0;
	else if (data->side == 0 && data->ray_dir_x < 0)
		data->tex_num = 1;
	else if (data->side == 1 && data->ray_dir_y > 0)
		data->tex_num = 2;
	else
		data->tex_num = 3;
	if (data->side == 0)
		data->wall_x = player->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wall_x = player->pos_x + data->perp_wall_dist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * TEX_WIDTH);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_x = 64 - data->tex_x - 1;
	if (data->side == 1 && data->ray_dir_x < 0)
		data->tex_x = 64 - data->tex_x - 1;
}

void	draw_roof(t_map *map, int draw_start, int *y, int x)
{
	while (*y < draw_start)
	{
		set_pixel(map->frame, x, *y, map->ceiling);
		*y += 1;
	}
}

void	draw_floor(t_map *map, int *y, int x)
{
	while (*y < HEIGHT)
	{
		set_pixel(map->frame, x, *y, map->floor);
		*y += 1;
	}
}

void    draw(t_rayKsting *data, t_map *map, t_player *player, int x)
{
	int				y;
	int				d;
	double			step;
	double			tex_pos;
	unsigned int	color;

	y = 0;
	calc_draw_params(data, player);
	step = 1.0 * TEX_HEIGHT / data->line_height;
	tex_pos = (data->draw_start - data->pitch - HEIGHT / 2
			+ data->line_height / 2) * step;
	draw_roof(map, data->draw_start, &y, x);
	while (y <= data->draw_end)
	{
		data->tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = get_pixel(map->tex[data->tex_num], data->tex_x, data->tex_y);
		if (data->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		set_pixel(map->frame, x, y, color);
		y++;
	}
	draw_floor(map, &y, x);
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

void    ray_k_string(t_map *map, t_player *player)
{
	int			x;
	int			y;
	t_rayKsting	ray_data;

	x = 0;
	while (x < WIDTH)
	{
		rayKsting_init(player, &ray_data, x);
		dda(&ray_data, map->map_cpy);
		draw(&ray_data, map, player, x);
		x++;
	}
	mlx_put_image_to_window(map->mlx->display, map->mlx->win,
		map->frame->img, 0, 0);
}
