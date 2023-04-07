/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:24:46 by jtoulous          #+#    #+#             */
/*   Updated: 2022/09/29 11:03:04 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	z;
	int	rec;

	if (c >= 256)
		c = c % 256;
	rec = -1;
	z = 0;
	while (s[z])
	{
		if (s[z] == c)
			rec = z;
		z++;
	}
	if (s[z] == c)
		rec = z;
	if (rec == -1)
		return (0);
	return ((char *)s + rec);
}
