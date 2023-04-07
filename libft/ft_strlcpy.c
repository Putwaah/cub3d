/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:44:56 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/01 01:24:57 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	z;

	if (size == 0)
		return (ft_strlen(src));
	z = 0;
	while (src[z] && z < size - 1)
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = '\0';
	return (ft_strlen(src));
}
