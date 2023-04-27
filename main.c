/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:41:28 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/20 09:49:52 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*parsing(int argc, char **argv)
{
	t_map	*map;
	
	if (argc != 2)
	{
		printf("Error arguments\n");
		return (NULL);
	}
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		exit (1);
	init_struct(map);
	open_and_copy(argv, map);
	check_params(map, argv);
	for (int z = 0; map->map_cpy[z]; z++)
	{
		printf("map[%d] %s", z, map->map_cpy[z]);
	}
	for (int z = 0; map->param_cpy[z]; z++)
	{
		printf("param[%d] %s", z, map->param_cpy[z]);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = parsing(argc, argv);
	game.player = init_player_data(game.map->map_cpy);
	game.player->key_release = 0;
	ray_k_string(game.map, game.player);
	//mlx_key_hook(game.map->mlx->win, &handle_key, (void *)&game);
	mlx_hook(game.map->mlx->win, 2, 1L << 0, press_key, (void *)&game);
	mlx_hook(game.map->mlx->win, 3, 1L << 1, release_key, NULL);
	mlx_loop(game.map->mlx->display);
	return (0);
}