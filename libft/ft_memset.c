/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:10:57 by jtoulous          #+#    #+#             */
/*   Updated: 2022/09/28 16:05:37 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pt;
	size_t			z;

	z = 0;
	pt = (unsigned char *)s;
	while (z < n)
	{
		pt[z] = c;
		z++;
	}
	return (s);
}
