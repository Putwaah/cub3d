/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:41:24 by jtoulous          #+#    #+#             */
/*   Updated: 2023/02/16 10:28:29 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list			*fnl;

	fnl = malloc(sizeof(t_list));
	if (!fnl)
		return (0);
	fnl->env_copy = (char *)content;
	fnl->next = NULL;
	return (fnl);
}
