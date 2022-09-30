/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:31:03 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/30 21:51:56 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	ft_putimg_end(t_data *session, char *imgfile, int x, int y)
{
	void	*img;
	int		*imgheight;
	int		*imgwidth;

	imgheight = &session->blocheight2;
	imgwidth = &session->blocwidth2;
	img = mlx_xpm_file_to_image(session->mlx, imgfile, imgwidth, imgheight);
	mlx_put_image_to_window (session->mlx, session->win, img, x, y);
	mlx_destroy_image(session->mlx, img);
}

void	ft_put_enemy(t_data *session)
{
	ft_putimg(session, session->imgfloor, session->x, session->y);
	ft_putimg(session, session->imgenemy, session->x, session->y);
}
