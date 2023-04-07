/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:28 by jtoulous          #+#    #+#             */
/*   Updated: 2023/03/02 12:21:42 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	free_loop(char **str)
{
	int	z;

	z = 0;
	if (str)
	{
		while (str[z])
		{
			free (str[z]);
			z++;
		}
		free (str);
	}
	str = NULL;
}*/

void	mega_free(char *s1, char *s2, char *s3, char *s4)
{
	if (s1 != NULL)
		free (s1);
	if (s2 != NULL)
		free (s2);
	if (s3 != NULL)
		free (s3);
	if (s4 != NULL)
		free (s4);
}

/*void	free_lst(t_list *lst)
{
	t_list	*tmp;
	
	if ()
	tmp = lst->next;
	while (lst)
	{
		if (lst->content)
			free (lst->content);
			
	}
}*/
