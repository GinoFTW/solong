/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:36:55 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/30 12:33:34 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

int	ft_keypress(int keyinput, t_data *session)
{
	if (keyinput == 53)
	{
		mlx_destroy_window(session->mlx, session->win);
		ft_freemem(session);
		exit (0);
	}
	if (session->death >= 1 || session->end >= 1)
		return (keyinput);
	else if (keyinput == 0)
		moveplayer(keyinput, session);
	else if (keyinput == 1)
		moveplayer(keyinput, session);
	else if (keyinput == 2)
		moveplayer(keyinput, session);
	else if (keyinput == 13)
		moveplayer(keyinput, session);
	return (keyinput);
}

void	data_init(t_data *session)
{
	session->imgbloc = "sprites/brick.xpm";
	session->imgplayer = "sprites/RFire_Warrior_IdleFireSword1.xpm";
	session->imgcollect = "sprites/Chest1.xpm";
	session->imgfloor = "sprites/floor.xpm";
	session->imgexit = "sprites/Door1.xpm";
	session->imgend = "sprites/End.xpm";
	session->imgenemy = "sprites/Enemy1.xpm";
	session->imgendmessage = "sprites/win.xpm";
	session->frame = 0;
	session->doorframe = 0;
	session->lockexit = 0;
	session->pondoor = 0;
	session->nbmoves = 0;
	session->nbplayer = 0;
	session->nbexit = 0;
	session->end = 0;
	session->death = 0;
	session->deathframe = 0;
	session->xscore = 5;
	session->yscore = 23;
	session->nbcollect = 0;
	session->directplayer = 'R';
	session->mlx = mlx_init();
	session->win = mlx_new_window(session->mlx, session->winwidth,
			session->winheight, "so long");
}

void	check_map_name(t_data *session)
{
	int		i;
	char	*filename;

	filename = session->mapfile;
	i = ft_strlen(filename);
	if (filename[i - 1] != 'r' && filename[i - 2] != 'e'
		&& filename[i - 3] != 'b' && filename[i - 4] != '.')
		ft_exit_maperror(8, session);
}

int	main(int argc, char **argv)
{
	t_data	session;

	if (argc != 2)
		ft_exit_maperror(8, &session);
	session.mapfile = argv[1];
	check_map_name(&session);
	session.map = ft_importmap(&session);
	data_init(&session);
	check_map(&session);
	mlx_hook(session.win, 2, 1L << 0, ft_keypress, &session);
	mlx_hook(session.win, 17, 0L, ft_exit, &session);
	first_stream(&session);
	mlx_loop_hook(session.mlx, ft_rendering, &session);
	mlx_loop(session.mlx);
	return (0);
}
