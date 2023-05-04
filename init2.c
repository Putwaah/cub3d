/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:36:59 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 15:39:43 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	north_south_init(char dir, t_player *player)
{
	if (dir == 'N')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (dir == 'S')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	init_dir(char dir, t_player *player)
{
	if (dir == 'N' || dir == 'S')
	{
		north_south_init(dir, player);
	}
	else if (dir == 'E')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (dir == 'W')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

t_player	*init_player_data(char **map, int x, int y)
{
	t_player	*player;
	static int	found = 0;

	player = malloc(sizeof(t_player));
	while (map[x] && found == 0)
	{
		while (map[x][y] && found == 0)
		{
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'E' || map[x][y] == 'W')
			{	
				init_dir(map[x][y], player);
				found = 1;
				player->pos_x = x + 0.5;
				player->pos_y = y + 0.5;
				map[x][y] = '0';
			}
			y++;
		}
		x++;
		if (found != 1)
			y = 0;
	}
	return (player);
}
