/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:01:54 by jtoulous          #+#    #+#             */
/*   Updated: 2022/09/29 16:07:21 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*slave;
	unsigned char	*dst;

	slave = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (!dst && !slave)
		return (0);
	if (dst > slave)
	{
		while (n > 0)
		{
			n--;
			dst[n] = slave[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dst);
}
