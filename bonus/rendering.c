/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:41:37 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/30 12:34:06 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	main_stream(t_data *session)
{
	session->x = 0;
	session->y = 0;
	while (session->y < session->maph)
	{
		if (session->map[session->y][session->x] == 'P')
			ft_put_player(session);
		if (session->map[session->y][session->x] == 'C')
			ft_put_collectible(session);
		if (session->map[session->y][session->x] == 'E')
			ft_put_exit(session);
		if (session->map[session->y][session->x] == 'S')
			ft_put_enemy(session);
		session->x++;
		if (session->map[session->y][session->x] == '\n')
		{
			session->x = 0;
			session->y++;
		}
	}
}

void	end_stream(t_data *session)
{
	int	ximgend;
	int	yimgend;

	ximgend = (session->winwidth - 250) / 2;
	yimgend = (session->winheight - 150) / 2;
	session->xscore = (session->winwidth - 250) / 2 + 5;
	session->yscore = (session->winheight - 150) / 2 + 130;
	if (session->end < 3)
	{
		mlx_clear_window(session->mlx, session->win);
		session->end++;
	}
	if (session->death == 1)
	{
		session->imgend = "sprites/End_death.xpm";
		session->imgendmessage = "sprites/lose.xpm";
	}
	ft_putimg_end(session, session->imgend, ximgend, yimgend);
	ft_putscore(session);
	mlx_string_put(session->mlx, session->win, session->xscore,
		session->yscore + 15, 0x00FFFFFF, "Tapez la touche echap pour quitter");
	ft_putimg_end(session, session->imgplayer, ximgend + 100, yimgend +50);
	if (session->frame < 120)
		ft_putimg_end(session, session->imgendmessage, ximgend, yimgend);
}

int	ft_rendering(t_data *session)
{
	if (session->end || session->death)
		end_stream(session);
	else
		main_stream(session);
	ft_animation(session);
	if (session->frame == 240)
	{
		session->frame = 0;
	}
	else
		session->frame++;
	if (session->frame % 30 == 0)
		if (!session->end && !session->death)
			parse_map_for_enemies(session);
	return (0);
}

void	first_stream(t_data *session)
{
	session->x = 0;
	session->y = 0;
	while (session->y < session->maph)
	{
		if (session->map[session->y][session->x] == 'P')
			ft_put_player(session);
		if (session->map[session->y][session->x] == '1')
			ft_putimg(session, session->imgbloc, session->x, session->y);
		if (session->map[session->y][session->x] == 'C')
			ft_put_collectible(session);
		if (session->map[session->y][session->x] == 'E')
			ft_put_exit(session);
		if (session->map[session->y][session->x] == 'S')
			ft_put_enemy(session);
		if (session->map[session->y][session->x] == '0')
			ft_putimg(session, session->imgfloor, session->x, session->y);
		session->x++;
		if (session->map[session->y][session->x] == '\n')
		{
			session->x = 0;
			session->y++;
		}
	}
	ft_putscore(session);
}

void	update_main_stream(t_data *session)
{
	int	i;

	i = 0;
	while (i < 6)
		ft_putimg(session, session->imgbloc, i++, 0);
	ft_putimg(session, session->imgfloor, session->lastxplayer,
		session->lastyplayer);
	ft_putscore(session);
}
