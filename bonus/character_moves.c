/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:11:44 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/28 19:50:50 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	change_map(char start, char end, t_data *session)
{
	if (start == 'E')
		session->pondoor = 0;
	if (*session->dest == 'E')
		session->pondoor = 1;
	*session->origin = start;
	*session->dest = end;
}

int	char_can_move(t_data *session)
{
	int	move;

	move = 0;
	if (*session->dest == 'C')
		session->nbcollect--;
	if (*session->dest == 'S')
	{
		session->death = 1;
	}
	if (*session->dest == 'E')
	{
		change_map('0', 'P', session);
		if (session->nbcollect == 0)
			ft_exit_gameover(session);
		move = 1;
	}
	else if (*session->dest != '1')
	{
		if (session->pondoor == 0)
			change_map('0', 'P', session);
		else
			change_map('E', 'P', session);
		move = 1;
	}
	return (move);
}

void	set_new_values(t_data *session, int x, int y)
{
	session->lastxplayer = session->xplayer;
	session->lastyplayer = session->yplayer;
	session->xplayer = x;
	session->yplayer = y;
	session->nbmoves += 1;
}

void	moveplayer(int keyinput, t_data *session)
{
	int	x;
	int	y;

	x = session->xplayer;
	y = session->yplayer;
	session->origin = &session->map[y][x];
	if (keyinput == 0)
	{
		x--;
		session->directplayer = 'L';
	}
	else if (keyinput == 1)
		y++;
	else if (keyinput == 2)
	{
		x++;
		session->directplayer = 'R';
	}
	else if (keyinput == 13)
		y--;
	session->dest = &session->map[y][x];
	if (char_can_move(session))
		set_new_values(session, x, y);
	update_main_stream(session);
}
