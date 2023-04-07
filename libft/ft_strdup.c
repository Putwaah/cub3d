/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:14:46 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/03 15:28:37 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*fnl;
	int		z;

	z = 0;
	fnl = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!fnl)
		return (0);
	while (s[z])
	{
		fnl[z] = s[z];
		z++;
	}
	fnl[z] = s[z];
	return (fnl);
}
