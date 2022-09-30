/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:31:03 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/30 21:50:19 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

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
