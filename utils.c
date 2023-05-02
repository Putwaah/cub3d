/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:46:21 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/02 15:52:19 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	int	z;

	z = -1;
	if (map->map_cpy != NULL)
		free (map->map_cpy);
	if (map->param_cpy != NULL)
		free (map->param_cpy);
	if (map->mlx != NULL)
		free (map->mlx);
	if (map->frame != NULL)
		free (map->frame);
	if (map->tex != NULL)
	{
		while (++z < 4)
			free (map->tex[z]);
		free (map->tex);
	}
	/*if (map->floor != NULL)
		free (map->floor);
	if (map->ceiling != NULL)
		free (map->ceiling);
	*/
}	

void	line_counter(t_map *map)
{
	char	*ret;

	ret = get_next_line(map->fd);
	if (ret == 0)
	{
		printf("Error gnl\n");
		free(map);
		exit(1);
	}
	while (ret != NULL)
	{
		free(ret);
		map->line++;
		ret = get_next_line(map->fd);
		if (ret == NULL)
			free(ret);
	}
}

char	*megatrim(t_map *map, const char *id, int i)
{
	char	*rtn;

	rtn = ft_strtrim(map->param_cpy[i], id);
	rtn = ft_strtrim(rtn, "\n");
	rtn = ft_strtrim(rtn, "\t");
	rtn = ft_strtrim(rtn, " ");
	return (rtn);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}	

void	end_game(t_map *map) //free tout et exit
{
	destroy_the_mlx(map->mlx, map->frame, map->tex);
	free_map(map);
	exit (69);
}

void	b_null(t_map *map)
{
	map->map_cpy = NULL;
	map->param_cpy = NULL;
	map->mlx = NULL;
	map->frame = NULL;
	map->tex = NULL;
	//map->ceiling = NULL;
	//map->floor = NULL;
}

void	destroy_the_mlx(t_mlx *mlx, t_img *frame, t_img **tex)
{
	int	z;

	z = -1;
	mlx_destroy_image(mlx->display, frame->img);
	while (++z < 4)
	{
		if (tex[z]->img != NULL)
			mlx_destroy_image(mlx->display, tex[z]->img);
	}
	mlx_destroy_window(mlx->display, mlx->win);
	mlx_destroy_display(mlx->display);
}

int	ft_putdigit_base(size_t nbr, int base)
{
	char *hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= - 1;
		write(1, "-", 1);
	}
	if (nbr >= base)
		ft_putdigit_base((nbr / base), base);
	nbr = hexa[nbr % base];
	return (nbr);
}
