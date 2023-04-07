/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:27:12 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/05 10:03:38 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_joinf(char *buf, char *str)
{
	char	*tmp;

	if (!buf || !str)
		return (NULL);
	tmp = ft_strjoin(buf, str);
	free(buf);
	return (tmp);
}

static char	*dnextl(char *buf)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}	
	rtn = ft_calloc(sizeof(char), (ft_strlen(buf) - i + 1));
	if (!rtn)
		return (0);
	i++;
	while (buf[i])
		rtn[j++] = buf[i++];
	free(buf);
	return (rtn);
}	

static char	*rdfile(int fd, char *s)
{
	char	*buf;
	int		i;

	if (!s)
		s = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{	
			free(buf);
			free(s);
			return (NULL);
		}
		buf[i] = 0;
		s = ft_joinf(s, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (s);
}

static char	*fline(char *buf)
{
	char	*rtn;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	rtn = ft_calloc(sizeof(char), i + 2);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{	
		rtn[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
	{	
		rtn[i] = '\n';
		i++;
	}	
	return (rtn);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_strdup("");
	buf[fd] = rdfile(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = fline(buf[fd]);
	buf[fd] = dnextl(buf[fd]);
	while (fd < 1024)
	{	
		free(buf[fd]);
		fd++;
	}		
	return (line);
}
