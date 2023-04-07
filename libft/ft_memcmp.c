/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 00:15:59 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/01 00:16:51 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			z;
	unsigned char	*slv1;
	unsigned char	*slv2;

	z = 0;
	slv1 = (unsigned char *)s1;
	slv2 = (unsigned char *)s2;
	while (z < n)
	{
		if (slv1[z] != slv2[z])
			return (slv1[z] - slv2[z]);
		z++;
	}
	return (0);
}
