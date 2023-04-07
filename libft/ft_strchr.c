/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:07:05 by jtoulous          #+#    #+#             */
/*   Updated: 2023/03/14 10:08:30 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	z;

	if (c > 256)
		c = c % 256;
	z = 0;
	while (s[z])
	{
		if (s[z] == c)
			return ((char *)s + z);
		z++;
	}
	if (s[z] == c)
		return ((char *)s + z);
	return (NULL);
}
