/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:16 by jmanet            #+#    #+#             */
/*   Updated: 2022/10/17 12:08:42 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

void	ft_exit_maperror(int errornum, t_data *session)
{
	ft_printf("Error\nIncorrect map file !\n");
	if (errornum == 1)
		ft_printf("Your map is not rectangular !");
	if (errornum == 2)
		ft_printf("Your map is not surrounded by walls !");
	if (errornum == 3)
		ft_printf("It must contain at least and maximum one Player (P)\n");
	if (errornum == 4)
		ft_printf("It must contain at least one Collectible (C)\n");
	if (errornum == 5)
		ft_printf("It must contain at least one Exit (E)\n");
	if (errornum == 6)
	{
		ft_printf("Check that your player can access");
		ft_printf(" to all Collectibles and Exit !\n");
	}
	if (errornum == 7)
		ft_printf("It contains some unknown characters");
	if (errornum == 8)
		ft_printf("You must add an argument with a map file .ber\n");
	if (errornum < 8)
		ft_freemem(session);
	exit(errornum);
}

void	ft_exit_gameover(t_data *session)
{
	session->end = 1;
}

int	ft_exit(t_data *session)
{
	ft_freemem(session);
	exit (0);
}

void	ft_exit_strerror(char *str)
{
	ft_printf("Error : %s : %s\n", str, strerror(errno));
	exit (0);
}
