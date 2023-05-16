/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:41:28 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/16 09:49:53 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_params(t_map *map, char **args)
{
	int		check[6];
	int		y;
	int		z;
	int		end;

	y = 0;
	z = -1;
	end = map_start(map, args);
	while (++z < 6)
		check[z] = 0;
	z = 0;
	while (z < end)
	{
		while (args[z][y] == ' ')
			y++;
		if (check_params(map, args[z], y, check) != 1)
		{
			free_loop(args);
			exit_error(map, "parameters problem");
		}
		z++;
		y = 0;
	}
	fnl_check(map, args, check);
}

static void	get_map(t_map *map, char **args)
{
	int	z;
	int	y;

	z = map_start(map, args);
	y = z;
	while (args[y])
		y++;
	map->map_cpy = ft_calloc(y - z + 1, sizeof(char *));
	y = 0;
	while (args[z])
	{
		map->map_cpy[y] = ft_strdup(args[z]);
		y++;
		z++;
	}
}

static void	open_and_copy(t_map *map, char *file)
{
	char	**args;
	int		len;

	len = ft_strlen(file) - 1;
	if (file[len] != 'b'
		|| file[len - 1] != 'u'
		|| file[len - 2] != 'c'
		|| file[len - 3] != '.')
		exit_error(map, "file format needs to be .cub");
	args = copy_file(map, file);
	get_params(map, args);
	get_map(map, args);
	free_loop(args);
}

static t_map	*parsing(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		printf("Error arguments\n");
		exit (0);
	}
	map = malloc(sizeof(t_map) * 1);
	if (!map)
		exit (1);
	b_null(map);
	map->param_cpy = ft_calloc(7, sizeof(char *));
	open_and_copy(map, argv[1]);
	check_map(map);
	init_params(map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = parsing(argc, argv);
	game.player = init_player_data(game.map->map_cpy, 0, 0);
	ray_k_string(game.map, game.player);
	mlx_hook(game.map->mlx->win, 2, 1L << 0, press_key, (void *)&game);
	mlx_hook(game.map->mlx->win, 3, 1L << 1, release_key, NULL);
	mlx_hook(game.map->mlx->win, 17, 1L << 0, end_game_cross, (void *)&game);
	mlx_loop(game.map->mlx->display);
	return (0);
}
