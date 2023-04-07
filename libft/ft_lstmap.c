/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:43:42 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/17 13:07:04 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*fnl;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	fnl = ft_lstnew(f(lst->content));
	if (!fnl)
		return (NULL);
	head = fnl;
	lst = lst->next;
	while (lst)
	{
		fnl->next = ft_lstnew(f(lst->content));
		if (!fnl)
		{
			ft_lstclear(&fnl, del);
			return (head);
		}
		lst = lst->next;
		fnl = fnl->next;
	}
	return (head);
}
