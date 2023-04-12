/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:59:59 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/12 10:55:07 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../cub3d/libft/libft.h"
# include "../cub3d/minilibx-linux/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

typedef struct s_image
{
	void	*img;
}	t_image;

typedef struct s_map
{
	mlx_t	*mlx;
	void	*win;
	int		fd;
	int		pos;
	int		len_map;
	int		line;
	char	**map_cpy;
	char	**param_cpy;
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
	char	*floor;
	char	*ceiling;
}	t_map;

/*init.c*/
void	init_struct(t_map *map);
void	init_map(t_map *map);

/*utils.c*/
void	free_map(t_map *map);	
void	line_counter(t_map *map);
int		ft_tablen(char **str);

/*check_map.c*/
void	copy_map(t_map *map, char **argv);
void	open_and_copy(char **argv, t_map *map);
void	check_map(t_map *map);

/*check_params.c*/
void	check_params(t_map *map, char **argv);

/*handle.c*/
void	handle_key(mlx_key_data_t key, void *param);
#endif
