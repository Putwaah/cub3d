/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:15:37 by jtoulous          #+#    #+#             */
/*   Updated: 2022/09/27 17:41:28 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*fnl;
	unsigned char	*to_copy;
	size_t			z;

	z = 0;
	fnl = (unsigned char *)dest;
	to_copy = (unsigned char *)src;
	if (!fnl && !to_copy)
		return (NULL);
	while (z < n)
	{
		fnl[z] = to_copy[z];
		z++;
	}
	return ((void *)fnl);
}
