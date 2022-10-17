/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:32:27 by jmanet            #+#    #+#             */
/*   Updated: 2022/10/17 12:07:57 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

# include <mlx.h>
# include "../getnextline/get_next_line.h"
# include "../libftprintf/includes/ft_printf.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*bloc;
	void	*player;
	void	*collect;
	void	*exit;
	char	*imgbloc;
	char	*imgplayer;
	char	*imgcollect;
	char	*imgfloor;
	char	*imgexit;
	char	*imgend;
	char	*imgendmessage;
	char	*imgenemy;
	char	*mapfile;
	char	*origin;
	char	*dest;
	char	**map;
	char	**tempmap;
	char	directplayer;
	char	directenemy;
	size_t	maph;
	size_t	mapw;
	int		blocwidth;
	int		blocheight;
	int		blocwidth2;
	int		blocheight2;
	int		winwidth;
	int		winheight;
	int		xplayer;
	int		yplayer;
	int		xenemy;
	int		yenemy;
	int		lastxplayer;
	int		lastyplayer;
	int		xscore;
	int		yscore;
	int		end;
	int		death;
	size_t	x;
	size_t	y;
	int		nbcollect;
	int		doorframe;
	int		deathframe;
	int		lockexit;
	int		pondoor;
	int		frame;
	int		nbmoves;
	int		nbplayer;
	int		nbexit;
}	t_data;

void	parsing_map(t_data *session);
void	ft_exit_gameover(t_data *session);
void	ft_animation(t_data *session);
void	ft_exit_maperror(int errornum, t_data *session);
void	ft_freemem(t_data *session);
void	check_map(t_data *session);
void	free_map(t_data *session);
void	free_temp_map(t_data *session);
void	first_stream(t_data *session);
void	update_main_stream(t_data *session);
void	end_stream(t_data *session);
int		char_move(char *start, char *end, t_data *session);
int		ft_exit(t_data *session);
int		ft_rendering(t_data *session);
size_t	mapsize(char *fichiermap);
char	**ft_importmap(t_data *session);
void	moveplayer(int keyinput, t_data *session);
void	ft_putscore(t_data *session);
void	ft_putimg(t_data *session, char *imgfile, int x, int y);
void	ft_putimg_end(t_data *session, char *imgfile, int x, int y);
void	ft_put_player(t_data *session);
void	ft_put_enemy(t_data *session);
void	ft_put_collectible(t_data *session);
void	ft_put_exit(t_data *session);
void	ft_exit_strerror(char *str);
void	ft_putimg(t_data *session, char *imgfile, int x, int y);
void	anim_enemy(t_data *session);
void	parse_map_for_enemies(t_data *session);
void	anim_player_death(t_data *session);
#endif
