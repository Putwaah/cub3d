/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:29:59 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/14 16:34:20 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_reverse(const char *s, int c)
{
	size_t	z;

	if (c > 256)
		c = c % 256;
	z = 0;
	while (s[z])
	{
		if (s[z] == c)
			return ((char *)s - s[z]);
		z++;
	}
	if (s[z] == c)
		return ((char *)s - s[z]);
	return (0);
}
