/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:16:58 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/05 16:19:06 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*transformation(int n, int z, char *fnl)
{
	fnl[z + 1] = '\0';
	while (n > 0)
	{
		fnl[z] = (n % 10) + '0';
		n = n / 10;
		z--;
	}
	return (fnl);
}

static char	*for_min_int(char *fnl)
{
	fnl[0] = '-';
	fnl[1] = '2';
	fnl[2] = '1';
	fnl[3] = '4';
	fnl[4] = '7';
	fnl[5] = '4';
	fnl[6] = '8';
	fnl[7] = '3';
	fnl[8] = '6';
	fnl[9] = '4';
	fnl[10] = '8';
	fnl[11] = '\0';
	return (fnl);
}

static int	nb_xxx(int n)
{
	int	nb_xxx;

	nb_xxx = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		nb_xxx++;
	}
	while (n >= 10)
	{
		n = n / 10;
		nb_xxx++;
	}
	return (nb_xxx);
}

char	*ft_itoa(int n)
{
	char	*fnl;
	int		z;

	fnl = ft_calloc(nb_xxx(n) + 1, sizeof(char));
	if (fnl == 0)
		return (0);
	if (n == -2147483648)
		for_min_int(fnl);
	if (n == -2147483648)
		return (fnl);
	if (n == 0)
	{
		fnl[0] = 0 + '0';
		return (fnl);
	}
	if (n < 0)
	{
		fnl[0] = '-';
		n = n * -1;
		z = nb_xxx(n);
	}
	else
		z = nb_xxx(n) - 1;
	fnl = transformation(n, z, fnl);
	return (fnl);
}
