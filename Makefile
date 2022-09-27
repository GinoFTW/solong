# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 11:31:39 by jmanet            #+#    #+#              #
#    Updated: 2022/09/23 12:31:10 by jmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong

SRCS = srcs/solong.c srcs/parsing_map.c srcs/character_moves.c srcs/rendering.c srcs/rendering_utils.c srcs/rendering_utils2.c srcs/sprites_animations.c srcs/check_map.c srcs/mem_utils.c srcs/exit.c getnextline/get_next_line.c getnextline/get_next_line_utils.c

LIBS = -lmlx ${LIBFTPRINTF}

LIBFTPRINTF = libftprintf/libftprintf.a

INCLUDES = includes/

CC = gcc

FLAGS = -Wall -Werror -Wextra -framework Appkit -framework OpenGL

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${SRCS} ${LIBFTPRINTF}
	${CC} ${SRCS} -I ${INCLUDES} ${LIBS} ${FLAGS} -o ${NAME}

${LIBFTPRINTF} :
	make -C libftprintf/

clean :
	rm -f ${OBJS}
	make fclean -C libftprintf/
fclean : clean
	rm -f ${NAME}
	rm -f ${LIBFTPRINT}
re : clean fclean all
