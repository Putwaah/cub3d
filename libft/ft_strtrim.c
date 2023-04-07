/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:21:34 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/06 17:15:59 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_set(const char s, const char *set)
{
	int	z;

	z = 0;
	while (set[z])
	{
		if (s == set[z])
			return (1);
		z++;
	}
	return (0);
}	

static size_t	check_end(const char *s, const char *set, size_t z)
{
	while (s[z])
	{
		if (check_set(s[z], set) != 1)
			return (0);
		z++;
	}
	return (1);
}

static size_t	fnl_size(const char *s, const char *set)
{
	size_t	z;
	size_t	size;

	z = 0;
	size = 0;
	while (check_set(s[z], set) == 1)
		z++;
	while ((check_set(s[z], set) != 1 || check_end(s, set, z) != 1)
		&& s[z] != '\0')
	{
		z++;
		size++;
	}
	return (size);
}	

char	*ft_strtrim(const char *s, const char *set)
{
	char	*fnl;
	size_t	z;
	size_t	y;

	z = 0;
	y = 0;
	fnl = ft_calloc(fnl_size(s, set) + 1, sizeof(char));
	if (!fnl)
		return (0);
	while (check_set(s[z], set) == 1)
		z++;
	while ((check_set(s[z], set) != 1 || check_end(s, set, z) != 1)
		&& s[z] != '\0')
	{
		fnl[y] = s[z];
		z++;
		y++;
	}
	return (fnl);
}
