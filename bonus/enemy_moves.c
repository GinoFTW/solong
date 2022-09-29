/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:08:59 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/29 15:14:21 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

int	get_direction(void)
{
	unsigned int	move;
	int				fd;

	fd = open("/dev/urandom", O_RDONLY);
	read(fd, &move, sizeof(unsigned int));
	move = move % 4;
	close(fd);
	return (move);
}

void	move_enemy(t_data *session)
{
	int	xdest;
	int	ydest;
	int	direction;

	direction = get_direction();
	xdest = session->xenemy;
	ydest = session->yenemy;
	if (direction == 0)
		xdest = session->xenemy - 1;
	if (direction == 1)
		ydest = session->yenemy - 1;
	if (direction == 2)
		xdest = session->xenemy + 1;
	if (direction == 3)
		ydest = session->yenemy + 1;
	if (session->map[ydest][xdest] == 'P')
		session->death = 1;
	if (session->map[ydest][xdest] == '0')
		session->map[ydest][xdest] = 'T';
	else
		session->map[session->yenemy][session->xenemy] = 'T';
}

void	maj_map(t_data *session)
{
	session->x = 0;
	session->y = 0;
	while (session->y < session->maph)
	{
		if (session->map[session->y][session->x] == 'S')
		{
			session->map[session->y][session->x] = '0';
			ft_putimg(session, session->imgfloor, session->x, session->y);
		}
		if (session->map[session->y][session->x] == 'T')
		{
			session->map[session->y][session->x] = 'S';
			ft_put_enemy(session);
		}
		session->x++;
		if (session->map[session->y][session->x] == '\n')
		{
			session->x = 0;
			session->y++;
		}
	}
}

void	parse_map_for_enemies(t_data *session)
{
	session->x = 0;
	session->y = 0;
	while (session->y < session->maph)
	{
		if (session->map[session->y][session->x] == 'S')
		{
			session->xenemy = session->x;
			session->yenemy = session->y;
			move_enemy(session);
		}
		session->x++;
		if (session->map[session->y][session->x] == '\n')
		{
			session->x = 0;
			session->y++;
		}
	}
	maj_map(session);
}
