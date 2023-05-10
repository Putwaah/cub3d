/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:33:19 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/10 17:33:34 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	char_check(char to_check)
{
	if (to_check != '0' && to_check != '1' && to_check != 'N'
		&& to_check != 'S' && to_check != 'W' && to_check != 'E'
		&& to_check != ' ' && to_check != '\0' && to_check != '\n')
		return (0);
	return (1);
}

int	check_tab(int *check, int max)
{
	int	z;

	z = 0;
	while (z < max)
	{
		if (check[z] != 1)
			return (0);
		z++;
	}
	return (1);
}

int	*init_tab(int max_line_len)
{
	int	*rtn;
	int	z;

	z = 0;
	rtn = malloc(sizeof(int) * max_line_len);
	while (z < max_line_len)
	{
		rtn[z] = 0;
		z++;
	}
	return (rtn);
}

int	max_line_len(char **map)
{
	int	z;
	int	max;

	max = 0;
	z = 0;
	while (map[z])
	{
		if (ft_strlen(map[z]) > max)
			max = ft_strlen(map[z]);
		z++;
	}
	return (max);
}

int	tab_count(char **to_count)
{
	int	z;

	z = 0;
	while (to_count[z])
		z++;
	return (z);
}
