/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:00:53 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/30 22:10:50 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	ft_putscore(t_data *session)
{
	char	*score;
	char	*str1;
	char	*str2;

	str1 = ft_strdup("Nombre de mouvements : ");
	str2 = ft_itoa(session->nbmoves);
	score = ft_strjoin(str1, str2);
	mlx_string_put(session->mlx, session->win, session->xscore,
		session->yscore, 0x00FFFFFF, score);
	free(score);
	free(str1);
	free(str2);
}

void	ft_putimg(t_data *session, char *imgfile, int x, int y)
{
	void	*img;
	int		*imgheight;
	int		*imgwidth;

	imgheight = &session->blocheight;
	imgwidth = &session->blocwidth;
	img = mlx_xpm_file_to_image(session->mlx, imgfile, imgwidth, imgheight);
	x = x * (session->blocwidth);
	y = y * (session->blocheight);
	mlx_put_image_to_window (session->mlx, session->win, img, x, y);
	mlx_destroy_image(session->mlx, img);
}

void	ft_put_player(t_data *session)
{
	ft_putimg(session, session->imgfloor, session->x, session->y);
	if (session->pondoor == 1)
		ft_putimg(session, session->imgexit, session->x, session->y);
	ft_putimg(session, session->imgplayer, session->x, session->y);
}

void	ft_put_collectible(t_data *session)
{
	ft_putimg(session, session->imgfloor, session->x, session->y);
	ft_putimg(session, session->imgcollect, session->x, session->y);
}

void	ft_put_exit(t_data *session)
{
	ft_putimg(session, session->imgfloor, session->x, session->y);
	ft_putimg(session, session->imgexit, session->x, session->y);
}
