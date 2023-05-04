/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:11:28 by jtoulous          #+#    #+#             */
/*   Updated: 2022/11/03 18:11:30 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*copy_2(char buf, char *line, char *new_line, size_t z)
{
	if (buf == '\n')
		new_line[z] = '\n';
	if (line)
		free(line);
	return (new_line);
}

char	*copy(char *buf, char *line, size_t z, size_t y)
{
	char	*new_line;

	new_line = ft_calloc(ft_double_strlen(line, buf) + 1, sizeof(char));
	if (!new_line)
	{	
		free (line);
		return (NULL);
	}
	if (line)
	{
		while (line[z])
		{
			new_line[z] = line[z];
			z++;
		}
	}
	while (buf[y] && buf[y] != '\n')
	{
		new_line[z] = buf[y];
		z++;
		y++;
	}
	copy_2(buf[y], line, new_line, z);
	return (new_line);
}

int	newline_check(char *buf)
{
	size_t	z;

	z = 0;
	while (buf[z])
	{
		if (buf[z] == '\n')
			return (1);
		z++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = copy(buf, line, 0, 0);
	if (newline_check(buf) == 1)
	{
		clean(buf, 0, 0);
		return (line);
	}
	line = read_the_fkin_file(fd, buf, line);
	if (!line)
		return (NULL);
	clean(buf, 0, 0);
	return (line);
}
