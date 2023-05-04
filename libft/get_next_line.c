/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:27:12 by agoichon          #+#    #+#             */
/*   Updated: 2023/05/03 16:15:35 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char	*ft_joinf(char *buf, char *str)
{
	char	*tmp;

	if (!buf || !str)
		return (NULL);
	tmp = ft_strjoin(buf, str);
	free(buf);
	return (tmp);
}

char	*dnextl(char *buf)
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
	if (rtn[0] == '\0')
	{
		free(rtn);
		rtn = NULL;
	}
	return (rtn);
}	

char	*rdfile(int fd, char *s)
{
	char	*buf;
	int		i;

	if (!s)
		s = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
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

char	*fline(char *buf)
{
	char	*rtn;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	rtn = ft_calloc(sizeof(char), i + 2);
	if (!rtn)
		return (NULL);
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
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = rdfile(fd, buf);
	if (!buf)
		return (NULL);
	line = fline(buf);
	buf = dnextl(buf);
	return (line);
}
