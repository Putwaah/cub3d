/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:10:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/16 09:52:37 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static char	*megatrim(t_map *map, const char *id, int i)
{
	char	*rtn;
	char	*tmp;

	tmp = ft_strtrim(map->param_cpy[i], id);
	rtn = ft_strtrim(tmp, "\n");
	free (tmp);
	tmp = ft_strtrim(rtn, "\t");
	free (rtn);
	rtn = ft_strtrim(tmp, " ");
	free (tmp);
	return (rtn);
}

void	load_texture(t_map *map, char *str, int i, int dir)
{
	char	*tmp;
	int		w;
	int		h;

	w = TEX_WIDTH;
	h = TEX_HEIGHT;
	tmp = megatrim(map, str, i);
	if (access(tmp, F_OK) != 0)
	{
		printf("%s not found\n", tmp);
		free(tmp);
		end_game(map);
	}
	map->tex[dir]->img = mlx_xpm_file_to_image(map->mlx->display, tmp, &w, &h);
	if (!map->tex[dir]->img)
	{	
		printf("error loading %s\n", tmp);
		free (tmp);
		end_game(map);
	}
	map->tex[dir]->addr = mlx_get_data_addr(map->tex[dir]->img,
			&map->tex[dir]->bpp, &map->tex[dir]->line_len,
			&map->tex[dir]->endian);
	free(tmp);
}

static void	check_colors(t_map *map, char **colors, int z, int y)
{	
	if (tab_count(colors) != 3)
	{
		free_loop(colors);
		end_game(map);
	}
	while (colors[z])
	{
		while (colors[z][y])
		{
			if ((colors[z][y] < '0' || colors[z][y] > '9')
					&& colors[z][y] != ',')
			{
				printf("colors values need to be between 0 and 255\n");
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
	count_virgule(map, tmp);
	split = ft_split(tmp, ',');
	free(tmp);
	check_colors(map, split, 0, 0);
	r = ft_atoi(split[0]);
	v = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r > 255 || v > 255 || b > 255)
	{
		printf("colors values need to be between 0 and 255\n");
		free_loop(split);
		end_game(map);
	}
	if (str[0] == 'F')
		map->floor = (r << 16) | (v << 8) | b;
	else
		map->ceiling = (r << 16) | (v << 8) | b;
	free_loop(split);
}
