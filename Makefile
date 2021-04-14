# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:36:42 by jodufour          #+#    #+#              #
#    Updated: 2021/04/14 21:43:07 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pathfinder
CC		=	gcc -c -o
LINKER	=	gcc -o
MAKEDIR	=	mkdir -p
RM		=	rm -rf

SRCD	=	srcs/
OBJD	=	objs/
INCLUDE	=	includes

SRCS	=	\
			main.c				\
			pf_setup.c			\
			pf_solve.c			\
			pf_pause.c			\
			pf_strlen.c			\
			pf_strdup.c			\
			pf_strchr.c			\
			pf_strjoin.c		\
			pf_err_msg.c		\
			pf_get_map.c		\
			pf_wait_quit.c		\
			pf_print_map.c		\
			pf_print_dim.c		\
			pf_check_map.c		\
			pf_get_matrix.c		\
			pf_print_matrix.c

OBJS	:=	${SRCS:.c=.o}
OBJS	:=	${addprefix ${OBJD}, ${OBJS}}
DEPS	=	${OBJS:.o=.d}

CFLAGS	=	-Wextra -Wall -MMD -I ${INCLUDE}
LDFLAGS	=	-lncurses

ifeq (${DEBUG}, true)
	CFLAGS	+=	-g
endif

${NAME}:	${OBJS}
	${LINKER} ${NAME} ${LDFLAGS} $^

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re




