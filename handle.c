/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:53:37 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/12 10:37:49 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	handle_key(int key, void *param)
{
	t_map	*map;
	map = (t_map *)param;
	
	if (key == XK_Escape)
		end_game(map);
	if (key == XK_w)
	{
	}
	if (key == XK_a)
	{
	}
	if (key == XK_d)
	{
	}
	if (key == XK_s)
	{}
}
