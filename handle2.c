/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:26:28 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 16:26:09 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_left(t_map	*map, t_player	*player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos_x + (-player->dir_y) * SPEED;
	next_y = player->pos_y + player->dir_x * SPEED;
	if (map->map_cpy[(int)next_x][(int)next_y] == '0')
	{	
		player->pos_x = next_x;
		player->pos_y = next_y;
		ray_k_string(map, player);
	}
}

static void	move_right(t_map *map, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos_x + player->dir_y * SPEED;
	next_y = player->pos_y + (-player->dir_x) * SPEED;
	if (map->map_cpy[(int)next_x][(int)next_y] == '0')
	{	
		player->pos_x = next_x;
		player->pos_y = next_y;
		ray_k_string(map, player);
	}
}

static void	move_forward(t_map *map, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos_x + player->dir_x * SPEED;
	next_y = player->pos_y + player->dir_y * SPEED;
	if (map->map_cpy[(int)next_x][(int)next_y] == '0')
	{
		player->pos_x = next_x;
		player->pos_y = next_y;
		ray_k_string(map, player);
	}
}

static void	move_backward(t_map *map, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos_x - player->dir_x * SPEED;
	next_y = player->pos_y - player->dir_y * SPEED;
	if (map->map_cpy[(int)next_x][(int)next_y] == '0')
	{
		player->pos_x = next_x;
		player->pos_y = next_y;
		ray_k_string(map, player);
	}
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
	return (0);
}