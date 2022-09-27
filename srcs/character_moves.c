/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:11:44 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/23 10:48:55 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	change_map(char start, char end, char *origin, char *dest, t_data *session)
{
	if (start == 'E')
		session->pondoor = 0;
	if (*dest == 'E')
		session->pondoor = 1;
	*origin = start;
	*dest = end;
}

int	char_move(char *start, char *end, t_data *session)
{
	int	move;

	move = 0;
	if (*end == 'C')
		session->nbcollect--;
	if (*end == 'E')
	{
		change_map('0', 'P', start, end, session);
		if (session->nbcollect == 0)
			ft_exit_gameover(session);
		move = 1;
	}
	else if (*end != '1')
	{
		if (session->pondoor == 0)
			change_map('0', 'P', start, end, session);
		else
			change_map('E', 'P', start, end, session);
		move = 1;
	}
	return (move);
}

