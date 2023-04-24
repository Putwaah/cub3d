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
	//map->mlx = mlx_init(1500, 1000, "cub3d", true);
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
	game.player = init_player_data(game.map->map_cpy);//player pos, dir, etc ...
	ray_k_string(game.map, game.player);
	mlx_key_hook(game.map->mlx->display , &handle_key, (void *)&game);
	mlx_loop(game.map->mlx->display);
	return (0);
}
