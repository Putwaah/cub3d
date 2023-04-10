/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:59:59 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/10 15:27:35 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../cub3d/libft/libft.h"
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
	int		img_x;
	int		img_y;
}	t_image;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	int		fd;
	int		len_map;
	int		line;
	char	**map_cpy;
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
	char	*floor;
	char	*ceiling;
}	t_map;

/*init.c*/
void	init_struct(t_map *map);
void	open_and_copy(char **argv, t_map *map);

#endif
