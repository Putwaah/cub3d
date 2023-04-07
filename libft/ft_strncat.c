/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:42:41 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/13 10:17:50 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	x;
	unsigned int	dest_strlen;

	x = 0;
	dest_strlen = ft_strlen(dest);
	while (src[x] && nb > x)
	{
		dest[dest_strlen + x] = src[x];
		x++;
	}
	dest[dest_strlen + x] = '\0';
	return (dest);
}
