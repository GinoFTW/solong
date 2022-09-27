/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_animations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:38:52 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/22 13:19:43 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	anim_player_r(t_data *session)
{
	if (session->frame % 16 == 0)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword1.xpm";
	if (session->frame % 16 == 1)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword2.xpm";
	if (session->frame % 16 == 2)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword3.xpm";
	if (session->frame % 16 == 3)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword4.xpm";
	if (session->frame % 16 == 4)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword5.xpm";
	if (session->frame % 16 == 5)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword4.xpm";
	if (session->frame % 16 == 6)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword5.xpm";
	if (session->frame % 16 == 7)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword6.xpm";
	if (session->frame % 16 == 8)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword7.xpm";
	if (session->frame % 16 == 9)
		session->imgplayer = "sprites/RFire_Warrior_IdleFireSword8.xpm";
}

void	anim_player_l(t_data *session)
{
	if (session->frame % 16 == 0)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword1.xpm";
	if (session->frame % 16 == 1)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword2.xpm";
	if (session->frame % 16 == 2)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword3.xpm";
	if (session->frame % 16 == 3)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword4.xpm";
	if (session->frame % 16 == 4)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword5.xpm";
	if (session->frame % 16 == 5)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword4.xpm";
	if (session->frame % 16 == 6)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword5.xpm";
	if (session->frame % 16 == 7)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword6.xpm";
	if (session->frame % 16 == 8)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword7.xpm";
	if (session->frame % 16 == 9)
		session->imgplayer = "sprites/LFire_Warrior_IdleFireSword8.xpm";
}

void	anim_collectibles(t_data *session)
{
	if (session->frame == 0)
		session->imgcollect = "sprites/Chest1.xpm";
	if (session->frame == 30)
		session->imgcollect = "sprites/Chest4.xpm";
	if (session->frame == 60)
		session->imgcollect = "sprites/Chest2.xpm";
	if (session->frame == 90)
		session->imgcollect = "sprites/Chest3.xpm";
	if (session->frame == 120)
		session->imgcollect = "sprites/Chest2.xpm";
	if (session->frame == 150)
		session->imgcollect = "sprites/Chest3.xpm";
	if (session->frame == 180)
		session->imgcollect = "sprites/Chest4.xpm";
	if (session->frame == 210)
		session->imgcollect = "sprites/Chest1.xpm";
}

void	anim_exit(t_data *session)
{
	if (!session->nbcollect)
		if (!session->lockexit)
		{
			if (session->doorframe == 0)
				session->imgexit = "sprites/Door1.xpm";
			else if (session->doorframe == 30)
				session->imgexit = "sprites/Door2.xpm";
			else if (session->doorframe == 60)
				session->imgexit = "sprites/Door3.xpm";
			else if (session->doorframe == 90)
				session->imgexit = "sprites/Door4.xpm";
			else if (session->doorframe == 120)
				session->imgexit = "sprites/Door5.xpm";
			else if (session->doorframe == 150)
				session->imgexit = "sprites/Door5.xpm";
			else if (session->doorframe == 180)
				session->imgexit = "sprites/Door6.xpm";
			else if (session->doorframe == 210)
			{
				session->imgexit = "sprites/Door6.xpm";
				session->lockexit = 1;
			}
			session->doorframe++;
		}
}

void	ft_animation(t_data *session)
{
	if (session->directplayer == 'R')
		anim_player_r(session);
	else
		anim_player_l(session);
	anim_collectibles(session);
	anim_exit(session);
}
