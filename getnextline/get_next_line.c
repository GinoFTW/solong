/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:15:02 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/27 14:11:39 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffering(char *buffer, int fd)
{
	char	*tmp;
	int		rd;

	rd = BUFFER_SIZE;
	tmp = malloc(sizeof(*tmp) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (rd && !ft_is_endline(buffer))
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[rd] = '\0';
		if (!buffer)
		{
			buffer = malloc(sizeof(*buffer) * 1);
			buffer[0] = '\0';
		}
		buffer = ft_strjoin_gnl(buffer, tmp);
	}
	free (tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = ft_buffering (buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_keepline(buffer);
	buffer = ft_keep_after_line(buffer);
	return (line);
}

char	*ft_keepline(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_keep_after_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*newbuffer;

	i = ft_linelen(buffer);
	j = 0;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	newbuffer = malloc(sizeof(*newbuffer) * (ft_strlen_gnl(buffer) - i + 1));
	if (!newbuffer)
		return (NULL);
	i++;
	while (buffer[i])
		newbuffer[j++] = buffer[i++];
	newbuffer[j] = '\0';
	free (buffer);
	return (newbuffer);
}
