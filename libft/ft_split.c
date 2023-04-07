/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:32:15 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/13 19:15:50 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	liberate(char **fnl, int word)
{
	int	z;

	z = 0;
	while (z < word)
	{
		free (fnl[z]);
		z++;
	}
	free (fnl);
	return ;
}

static char	**fill_fnl(char **fnl, const char *s, char c, int z)
{
	int	y;
	int	word;

	y = 0;
	word = 0;
	while (s[z])
	{
		if (s[z] != c)
		{
			y = z;
			while (s[y] != c && s[y])
				y++;
			fnl[word] = ft_substr(s, z, y - z);
			if (!fnl)
			{
				liberate(fnl, word);
				return (NULL);
			}
			z = y;
			word++;
		}
		else
			z++;
	}
	return (fnl);
}

static int	m_size(const char *s, char c)
{
	int	z;
	int	y;
	int	x;

	z = 0;
	y = 0;
	x = 0;
	while (s[z])
	{
		if (s[z] != c)
		{
			y++;
			while (s[z] != c && s[z])
				z++;
		}
		else
		{
			x++;
			while (s[z] == c && s[z])
				z++;
		}
	}
	if (!s || y == 0)
		return (0);
	return (y);
}

char	**ft_split(const char *s, char c)
{
	char	**fnl;

	fnl = ft_calloc(m_size(s, c) + 1, sizeof(char *));
	if (!fnl)
		return (NULL);
	if (m_size(s, c) == 0)
	{
		fnl[0] = 0;
		return (fnl);
	}
	fnl = fill_fnl(fnl, s, c, 0);
	if (!fnl)
		return (NULL);
	fnl[m_size(s, c)] = 0;
	return (fnl);
}
