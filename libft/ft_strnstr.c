/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:51:15 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/17 12:52:21 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *haystack, const char *needle,
		size_t z, size_t len)
{
	int	y;

	y = 0;
	while (needle[y])
	{
		if (z >= len)
			return (0);
		if (haystack[z] != needle[y])
			return (0);
		z++;
		y++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	z;

	z = 0;
	if (needle[0] == '\0' && len == 0)
		return ((char *)haystack);
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[z] && z < len)
	{
		if (haystack[z] == needle[0])
		{
			if (check(haystack, needle, z, len) == 1 && z < len)
				return ((char *)haystack + z);
		}
		z++;
	}
	return (NULL);
}
