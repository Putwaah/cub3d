/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:45:48 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/03 18:12:19 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	z;
	unsigned int	y;

	if (size == 0 && (!src || !dst))
		return (0);
	z = 0;
	while (dst[z] != '\0' && z < size)
		z++;
	if (z >= size)
		return (size + ft_strlen(src));
	y = z;
	while (src[z - y] != '\0' && z < size - 1)
	{
		dst[z] = src[z - y];
		z++;
	}
	if (y < size)
		dst[z] = '\0';
	return (y + ft_strlen (src));
}
