/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:02:10 by jmanet            #+#    #+#             */
/*   Updated: 2022/09/27 14:12:29 by jmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 5

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
size_t	ft_linelen(char *str);
int		ft_is_endline(char *str);
char	*ft_keep_after_line(char *buffer);
char	*ft_newbuff(int fd);
char	*ft_keepline(char *buffer);
char	*ft_strjoin_gnl(char *s1, char *s2);
#endif
