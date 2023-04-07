/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:02:02 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/05 22:03:55 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*str;

	if ((nmeb * size == 1) && (size != 1))
		return (0);
	str = malloc(size * nmeb);
	if (!str)
		return (0);
	ft_memset(str, 0, nmeb * size);
	return (str);
}
