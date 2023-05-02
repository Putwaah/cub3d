/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/02 15:53:00 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_params(t_map *map, char **argv)
{
	int	i;
	int	tmp;

	map->fd = open(argv[1], O_RDONLY);
	tmp = map->line;
	map->line = 0;
	line_counter(map);
	close(map->fd);
	if (map->line - tmp < 6)
	{
		free_map(map);
		printf("Error line \n");
		exit(0);
	}
	map->param_cpy = malloc(sizeof(char *) * (map->line - tmp));
	i = 0;
	map->fd = open(argv[1], O_RDONLY);
	while (i < (map->line - tmp) - 2)
	{	
		map->param_cpy[i] = get_next_line(map->fd);
		i++;
	}
	map->param_cpy[i] = NULL;
	close(map->fd);
	init_params(map);
}

void	load_texture(t_map *map, char *str, int i, int dir)
{
	char	*tmp;
	int		w;
	int		h;

	w = WIDTH;
	h = HEIGHT;
	tmp = megatrim(map, str, i);
	if (access(tmp, F_OK) != 0)
		end_game(map);
	map->tex[dir]->img = mlx_xpm_file_to_image(map->mlx->display, tmp, &w, &h);
	map->tex[dir]->addr = mlx_get_data_addr(map->tex[dir]->img, &map->tex[dir]->bpp, &map->tex[dir]->line_len, &map->tex[dir]->endian);
	free(tmp);
}

void	load_color(t_map *map, char *str, int i)
{
	char	*tmp;
	char	**split;

	tmp = megatrim(map, str, i);
	split = ft_split(tmp, ',');
	free(tmp);
	tmp = triple_strjoin(split[0], split[1], split[2]);
	if (ft_atol_check(tmp) == 0)
		map->f = ft_atol(tmp);
		map->f = ft_putdigit_base(map->f, 16);
	printf("f = %d\n", map->f);
	free(tmp);
	free_split(split);
}	
