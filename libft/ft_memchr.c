/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:18:33 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/01 00:07:37 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*slv;
	size_t	z;

	z = 0;
	slv = (char *)s;
	while (z < n)
	{
		if (slv[z] == c % 256)
			return ((void *)slv + z);
		z++;
	}
	return (0);
}
