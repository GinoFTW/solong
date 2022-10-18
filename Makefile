# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 11:31:39 by jmanet            #+#    #+#              #
#    Updated: 2022/10/18 09:23:24 by jmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = srcs/solong.c srcs/parsing_map.c srcs/character_moves.c srcs/rendering.c srcs/rendering_utils.c srcs/rendering_utils2.c srcs/sprites_animations.c srcs/check_map.c srcs/mem_utils.c srcs/exit.c getnextline/get_next_line.c getnextline/get_next_line_utils.c

SRCS_BONUS = bonus/solong.c bonus/parsing_map.c bonus/character_moves.c bonus/enemy_moves.c bonus/rendering.c bonus/rendering_utils.c bonus/rendering_utils2.c bonus/sprites_animations.c bonus/sprites_animations2.c bonus/check_map.c bonus/mem_utils.c bonus/exit.c getnextline/get_next_line.c getnextline/get_next_line_utils.c

LIBS = -lmlx ${LIBFTPRINTF}

LIBFTPRINTF = libftprintf/libftprintf.a

INCLUDES = includes/

CC = gcc

FLAGS = -Wall -Werror -Wextra -framework Appkit -framework OpenGL

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${LIBFTPRINTF}
	${CC} ${SRCS} -I ${INCLUDES} ${LIBS} ${FLAGS} -o ${NAME}

bonus : ${OBJS_BONUS} ${LIBFTPRINTF}
	${CC} ${SRCS_BONUS} -I ${INCLUDES} ${LIBS} ${FLAGS} -o ${NAME}

${LIBFTPRINTF} :
	make -C libftprintf/

clean :
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}
	make fclean -C libftprintf/
fclean : clean
	rm -f ${NAME}
	rm -f ${LIBFTPRINT}
re : clean fclean all
