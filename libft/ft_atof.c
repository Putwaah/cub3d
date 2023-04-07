/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:42:58 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 16:44:00 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_pre(char *str)
{
	int		z;
	double	res;

	if (!str)
		return (0);
	z = 0;
	res = 0;
	while (str[z] != ',' && str[z] != '.' && str[z])
		z++;
	if (str[z] == '\0')
		return (0);
	z++;
	while (str[z] >= '0' && str[z] <= '9' && str[z])
	{
		if (str[z + 1] >= '0' && str[z + 1] <= '9')
			res = (res + (str[z] - '0')) * 10;
		else
			res = res + (str[z] - '0');
		z++;
	}
	while (res >= 1)
		res = res / 10;
	return (res);
}

static double	get_ante(char *str)
{
	int		z;
	double	res;

	res = 0;
	z = 0;
	if (!str)
		return (0);
	while (str[z] < '0' || str[z] > '9')
		z++;
	while ((str[z] != ',' && str[z] != '.' && str[z]
			&& (str[z] >= '0' && str[z] <= '9')) || str[z] == '-')
	{
		if (str[z] == '-')
			z++;
		if (str[z + 1] >= '0' && str[z + 1] <= '9')
			res = (res + (str[z] - '0')) * 10;
		else
			res = res + (str[z] - '0');
		z++;
	}
	return (res);
}

static int	get_sign(char *str)
{
	int	z;

	z = 0;
	while (str[z] < '0' || str[z] > '9')
	{
		if (str[z] == '-')
			return (-1);
	}
	return (1);
}

double	ft_atof(char *str)
{
	double	res_pre;
	double	res_ante;
	int		sign;

	sign = get_sign(str);
	res_pre = get_pre(str);
	res_ante = get_ante(str);
	return ((res_pre + res_ante) * sign);
}
