/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:48:12 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/05 18:22:13 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	right_spot(const char *str)
{
	int	z;

	z = 0;
	while (str[z] != '-' && str[z] != '+'
		&& (str[z] < '0' || str[z] > '9'))
	{
		if (str[z] != ' ' && (str[z] < 9 || str[z] > 13))
			return (-1);
		z++;
	}
	return (z);
}

int	ft_atoi(const char *str)
{
	int	z;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	z = right_spot(str);
	if (z == -1)
		return (0);
	if (str[z] == '-' || str[z] == '+')
	{
		if (str[z] == '-')
			sign = -1;
		z++;
	}
	while (str[z] >= '0' && str[z] <= '9')
	{
		if (str[z + 1] < '0' || str[z + 1] > '9')
			return ((res + (str[z] - '0')) * sign);
		res = (res + (str[z] - '0')) * 10;
		z++;
	}
	return (res);
}
