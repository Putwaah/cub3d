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

void	handle_key(mlx_key_data_t key, void *param)
{
	(void) param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		exit(1);
}
