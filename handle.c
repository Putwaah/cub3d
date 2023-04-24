/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:53:37 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/12 10:37:49 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_map *map, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos_x + player->dir_x * 0.1;
	next_y = player->pos_y + player->dir_y * 0.1;
	if (map->map_cpy[(int)next_x][(int)next_y] == '0')
	{
		player->pos_x = next_x;
		player->pos_y = next_y;
		ray_k_string(map, player);
	}
}

void	move_backward(t_map *map, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos_x - player->dir_x * 0.1;
	next_y = player->pos_y - player->dir_y * 0.1;
	if (map->map_cpy[(int)next_x][(int)next_y] == '0')
	{
		player->pos_x = next_x;
		player->pos_y = next_y;
		ray_k_string(map, player);
	}
}

/*void	move_left(t_map	*map, t_player	*player)
{
		ray_k_string(map, player);
}

void	move_right(t_map	*map, t_player *player)
{
		ray_k_string(map, player);
}

void	move_view_right(t_map *map ,t_player *player)
{
		ray_k_string(map, player);
}

void	move_view_right(t_map *map, t_player *player)
{
		ray_k_string(map, player);

}
*/
int	handle_key(int key, void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	if (key == XK_Escape)
		end_game(game->map);
	else if (key == XK_w)
		move_forward(game->map, game->player);
	//else if (key == XK_a)
	//	move_right(game->map->map_cpy, game->player)
	//else if (key == XK_d)
	//	move_left(game->map->map_cpy, game->player);
	else if (key == XK_s)
		move_backward(game->map, game->player);
	//else if (key == XK_Rigth)
	//	move_view_right(game->map->map_cpy, game->player);
	//else if (key == XK_Left)
	//	move_view_left(game->map->map_cpy, game->player);
	return (0);
}
