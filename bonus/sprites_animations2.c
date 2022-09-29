/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_animations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:38:52 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/29 11:35:18 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	anim_enemy(t_data *session)
{
	if (session->frame % 24 == 0)
		session->imgenemy = "sprites/Enemy1.xpm";
	if (session->frame % 24 == 6)
		session->imgenemy = "sprites/Enemy2.xpm";
	if (session->frame % 24 == 12)
		session->imgenemy = "sprites/Enemy3.xpm";
	if (session->frame % 24 == 18)
		session->imgenemy = "sprites/Enemy4.xpm";
}

void	anim_player_death(t_data *session)
{
	if (session->deathframe < 240)
	{
		if (session->deathframe == 1)
			session->imgplayer = "sprites/death1.xpm";
		if (session->deathframe == 30)
			session->imgplayer = "sprites/death2.xpm";
		if (session->deathframe == 60)
			session->imgplayer = "sprites/death3.xpm";
		if (session->deathframe == 90)
			session->imgplayer = "sprites/death4.xpm";
		if (session->deathframe == 120)
			session->imgplayer = "sprites/death5.xpm";
		if (session->deathframe == 150)
			session->imgplayer = "sprites/death6.xpm";
		if (session->deathframe == 180)
			session->imgplayer = "sprites/death7.xpm";
		if (session->deathframe == 210)
			session->imgplayer = "sprites/death8.xpm";
		if (session->deathframe == 220)
			session->imgplayer = "sprites/death9.xpm";
		if (session->deathframe == 230)
			session->imgplayer = "sprites/death10.xpm";
		session->deathframe++;
	}
}
