/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:19:44 by jtoulous          #+#    #+#             */
/*   Updated: 2023/02/16 10:26:35 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*fnl;
	size_t	z;

	z = 0;
	if (!s || start >= ft_strlen(s) || len <= 0)
	{
		fnl = ft_calloc(1, sizeof(char));
		if (!fnl)
			return (0);
		return (fnl);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	fnl = ft_calloc(len + 1, sizeof(char));
	if (!fnl)
		return (0);
	while (s[start] && len > 0)
	{
		fnl[z] = s[start];
		z++;
		start++;
		len--;
	}
	return (fnl);
}
