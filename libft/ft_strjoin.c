/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:18:54 by jtoulous          #+#    #+#             */
/*   Updated: 2023/02/13 15:07:21 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stamp(char *dst, char *src)
{
	int	z;
	int	y;

	z = 0;
	y = 0;
	while (dst[z])
		z++;
	while (src[y])
	{
		dst[z] = src[y];
		z++;
		y++;
	}
	dst[z] = '\0';
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*fnl;

	fnl = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (fnl == 0)
		return (0);
	ft_strlcpy(fnl, s1, ft_strlen(s1) + 1);
	ft_strlcat(fnl, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (fnl);
}

char	*triple_strjoin(char *s1, char *s2, char *s3)
{
	char	*fnl;

	fnl = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1,
			sizeof(char));
	if (!fnl)
		return (NULL);
	stamp(fnl, s1);
	stamp(fnl, s2);
	stamp(fnl, s3);
	return (fnl);
}

char	*strjoin_n_free(char *s1, char *s2)
{
	int		z;
	int		y;
	char	*fnl;

	z = 0;
	y = 0;
	fnl = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1,
			sizeof(char));
	if (s1)
	{	
		stamp(fnl, s1);
		free (s1);
	}
	if (s2)
	{
		stamp(fnl, s2);
		free (s2);
	}
	return (fnl);
}
