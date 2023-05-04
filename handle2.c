/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:26:28 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 14:56:22 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_view_left(t_map *map, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT_SPEED)
		- player->dir_y * sin(ROT_SPEED);
	player->dir_y = old_dir_x * sin(ROT_SPEED)
		+ player->dir_y * cos(ROT_SPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos (ROT_SPEED)
		- player->plane_y * sin(ROT_SPEED);
	player->plane_y = old_plane_x * sin(ROT_SPEED)
		+ player->plane_y * cos(ROT_SPEED);
	ray_k_string(map, player);
}

int	press_key(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == XK_Escape)
	{
		free (game->player);
		end_game(game->map);
	}
	else if (key == XK_w)
		move_forward(game->map, game->player);
	else if (key == XK_d)
		move_right(game->map, game->player);
	else if (key == XK_a)
		move_left(game->map, game->player);
	else if (key == XK_s)
		move_backward(game->map, game->player);
	else if (key == XK_Right)
		move_view_right(game->map, game->player);
	else if (key == XK_Left)
		move_view_left(game->map, game->player);
	game->player->key_release = 0;
	return (0);
}

int	release_key(int key, void *param)
{
	return (0);
}
