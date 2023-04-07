/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:41:31 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 16:42:35 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char ch)
{
	write (1, &ch, 1);
}

void	ft_putstr(char *str)
{
	int	z;

	z = 0;
	while (str[z])
	{
		ft_putchar(str[z]);
		z++;
	}
}

void	s_trimage(char *str, int trim_size)
{
	int	z;
	int	y;

	y = 0;
	z = 0;
	if (!str && str[0] == '\0')
		return ;
	while (z < trim_size)
		z++;
	while (str[z])
	{
		str[y] = str[z];
		y++;
		z++;
	}
	while (str[y])
	{
		str[y] = '\0';
		y++;
	}
}

void	m_trim(char *str, int start, int end)
{
	end++;
	if (!str && str[0] == '\0')
		return ;
	while (str[end])
	{
		str[start] = str[end];
		start++;
		end++;
	}
	while (str[start])
	{
		str[start] = '\0';
		start++;
	}
}

void	quick_kill(char *err_msg)
{
	if (err_msg)
		ft_putstr_fd(err_msg, 1);
	exit (0);
}
