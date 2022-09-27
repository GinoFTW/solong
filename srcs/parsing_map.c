/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:44:10 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/27 16:13:46 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

size_t	mapheight(t_data *session)
{
	int		fd;
	size_t	i;
	char	*line;

	i = 0;
	fd = open(session->mapfile, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_exit_maperror(9, session);
	}
	if (line)
	{
		while (line)
		{
			free(line);
			line = get_next_line(fd);
			i++;
		}
	}
	free(line);
	close(fd);
	return (i);
}

char	**ft_importmap(t_data *session)
{
	size_t	i;
	size_t	height;
	int		fd;
	char	**map;

	i = 0;
	height = mapheight(session);
	fd = open(session->mapfile, O_RDONLY);
	if (fd < 0)
		ft_exit_strerror(session->mapfile);
	map = malloc(sizeof(*map) * height + 1);
	if (!map)
		ft_exit_strerror("malloc map");
	while (i <= height)
		map[i++] = get_next_line(fd);
	close(fd);
	session->maph = height;
	session->mapw = ft_strlen(map[0]);
	session->winwidth = (session->mapw - 1) * 50;
	session->winheight = session->maph * 50;
	return (map);
}

void	parsing_map(t_data *session)
{
	session->x = 0;
	session->y = 0;
	while (session->y < session->maph)
	{
		if (session->map[session->y][session->x] == 'P')
		{
			session->nbplayer++;
			session->xplayer = session->x;
			session->yplayer = session->y;
		}
		if (session->map[session->y][session->x] == 'E')
			session->nbexit++;
		if (session->map[session->y][session->x] == 'C')
			session->nbcollect++;
		if (!ft_ischarset("1EC0P", session->map[session->y][session->x]))
			ft_exit_maperror(7, session);
		session->x++;
		if (session->map[session->y][session->x] == '\n')
		{
			session->x = 0;
			session->y++;
		}
	}
}
