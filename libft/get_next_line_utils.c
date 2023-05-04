/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:11:15 by jtoulous          #+#    #+#             */
/*   Updated: 2022/11/03 18:11:20 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			z;

	z = 0;
	tmp = (unsigned char *)s;
	while (z < n)
	{	
		tmp[z] = '\0';
		z++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	if (nmemb == 0 || size == 0)
	{
		pt = malloc(0);
		return (pt);
	}
	if (nmemb * size / size != nmemb)
		return (0);
	pt = malloc(size * nmemb);
	if (!pt)
		return (0);
	ft_bzero(pt, nmemb * size);
	return (pt);
}
*/
char	*read_the_fkin_file(int fd, char *buf, char *line)
{
	int	ret;

	while (newline_check(buf) != 1)
	{	
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		line = copy(buf, line, 0, 0);
		if (!line)
			return (NULL);
		if (ret <= 0 && line[0] == '\0')
		{
			free (line);
			return (NULL);
		}
		if (ret < BUFFER_SIZE)
			return (line);
	}
	return (line);
}

char	*clean(char *buf, size_t z, size_t y)
{
	while (buf[z] && buf[z] != '\n')
		z++;
	if (buf[z] == '\n')
	{
		z++;
		while (buf[z])
		{
			buf[y] = buf[z];
			z++;
			y++;
		}
		buf[y] = '\0';
	}
	else
		buf[0] = '\0';
	return (buf);
}

int	ft_double_strlen(char *line, char *buf)
{
	size_t	l;
	size_t	b;

	l = 0;
	b = 0;
	if (line)
	{
		while (line[l])
			l++;
	}
	if (buf)
	{
		while (buf[b])
			b++;
	}
	return (b + l);
}
