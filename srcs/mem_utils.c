/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:25:56 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/30 21:56:42 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	free_map(t_data *session)
{
	size_t	i;
	char	**map;

	i = 0;
	map = session->map;
	while (i < session->maph)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_temp_map(t_data *session)
{
	size_t	i;
	char	**map;

	i = 0;
	map = session->tempmap;
	while (i < session->maph)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_freemem(t_data *session)
{
	free_map(session);
	free(session->mlx);
}
