/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:07:18 by agoichon          #+#    #+#             */
/*   Updated: 2023/04/19 13:53:40 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *nptr)
{
	int			i;
	long long	n;

	n = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)
		|| nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n);
}

long long	ft_atol_check(const char *nptr)
{
	int			i;
	long long	n;

	n = 0;
	i = 0;
	if (nptr[i] == '\0')
		return (1);
	if (nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] > 57 || nptr[i] < 48)
			return (1);
		i++;
	}
	i = 0;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
				n = (n * 10) + (nptr[i] - '0');
		if (n > 2147483647)
			return (1);
		i++;
	}
	return (0);
}
