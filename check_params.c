/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/04 12:57:29 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

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
	map->param_cpy = ft_calloc(sizeof(char *), (map->line - tmp) + 1);
	i = 0;
	map->fd = open(argv[1], O_RDONLY);
	while (i < (map->line - tmp))
	{
		map->param_cpy[i] = get_next_line(map->fd);
		i++;
	}
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
	map->tex[dir]->addr = mlx_get_data_addr(map->tex[dir]->img,
			&map->tex[dir]->bpp, &map->tex[dir]->line_len,
			&map->tex[dir]->endian);
	free(tmp);
}

static int	tab_count(char **to_count)
{
	int	z;

	z = 0;
	while (to_count[z])
		z++;
	return (z);
}

static void	check_colors(t_map *map, char **colors)
{	
	int	z;
	int	y;

	z = 0;
	y = 0;
	if (tab_count(colors) != 3 || tab_count(colors) > 10)
	{
		free_loop(colors);
		end_game(map);
	}
	while (colors[z])
	{
		while (colors[z][y])
		{
			if (colors[z][y] < '0' || colors[z][y] > '9')
			{
				free_loop(colors);
				end_game(map);
			}
			y++;
		}
		y = 0;
		z++;
	}
}

void	load_color(t_map *map, char *str, int i)
{
	char	*tmp;
	char	**split;
	int		r;
	int		v;
	int		b;

	tmp = megatrim(map, str, i);
	split = ft_split(tmp, ',');
	free(tmp);
	r = ft_atoi(split[0]) % 256;
	v = ft_atoi(split[1]) % 256;
	b = ft_atoi(split[2]) % 256;
	if (str[0] == 'F')
		map->floor = (r << 16) | (v << 8) | b;
	else
		map->ceiling = (r << 16) | (v << 8) | b;
	free_split(split);
}
