/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:07:18 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/07 10:45:12 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *nptr)
{
	int			i;
	long long	n;
	int			s;

	s = 1;
	n = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n * s);
}

static int	compare_to_lim(const char *nptr, char *lim, int z)
{
	int	y;

	y = 0;
	while (nptr[z])
	{
		if (nptr[z] > lim[y])
			return (1);
		if (nptr[z] < lim[y])
			return (0);
		z++;
		y++;
	}
	return (0);
}	

static int	free_n_int(char *to_free, int rtn_val)
{
	free (to_free);
	return (rtn_val);
}

long long	ft_atol_check(const char *nptr)
{
	unsigned int	z;
	unsigned int	y;
	char			*lim;

	z = 0;
	lim = ft_strdup("9223372036854775807");
	while (nptr[z] == 32 || (nptr[z] >= 9 && nptr[z] <= 13))
		z++;
	if (nptr[z] == '-' || nptr[z] == '+')
	{	
		if (nptr[z++] == '-')
			lim[18] = '8';
	}	
	y = z;
	while (nptr[y])
	{	
		if (nptr[y] < '0' || nptr[y] > '9')
			return (free_n_int(lim, 1));
		y++;
	}
	if (y - z > ft_strlen(lim))
		return (free_n_int(lim, 1));
	if (y - z == ft_strlen(lim) && compare_to_lim(nptr, lim, z) == 1)
		return (free_n_int(lim, 1));
	return (free_n_int(lim, 0));
}
