/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:31:50 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/04 20:37:49 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*fnl;
	int		z;

	z = 0;
	if (!f || !s)
		return (NULL);
	fnl = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!fnl)
		return (0);
	while (s[z])
	{
		fnl[z] = f(z, s[z]);
		z++;
	}
	fnl[z] = '\0';
	return (fnl);
}	
