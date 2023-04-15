/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:21:34 by jtoulous          #+#    #+#             */
/*   Updated: 2023/04/15 14:14:42 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	l = ft_strlen(s1);
	if (set == 0)
		return ((char *)s1);
	if (s1 == 0)
		return ((char *)s1);
	while (ft_counter(s1[i], set) == 0)
		i++;
	while (ft_counter(s1[l - 1], set) == 0)
		l--;
	s2 = ft_substr(s1, i, (l - i));
	if (!s2)
		return (NULL);
	return (s2);
}
