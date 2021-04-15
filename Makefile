# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:36:42 by jodufour          #+#    #+#              #
#    Updated: 2021/04/15 22:24:26 by jodufour         ###   ########.fr        #
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
			main.c					\
			pf_setup.c				\
			pf_solve.c				\
			pf_pause.c				\
			pf_strlen.c				\
			pf_strdup.c				\
			pf_strchr.c				\
			pf_strjoin.c			\
			pf_err_msg.c			\
			pf_get_map.c			\
			pf_calc_ngb.c			\
			pf_calc_dist.c			\
			pf_wait_quit.c			\
			pf_print_map.c			\
			pf_print_dim.c			\
			pf_check_map.c			\
			pf_calc_t_ngb.c			\
			pf_calc_b_ngb.c			\
			pf_calc_l_ngb.c			\
			pf_calc_r_ngb.c			\
			pf_get_matrix.c			\
			pf_get_end_idx.c		\
			pf_get_low_idx.c		\
			pf_print_matrix.c		\
			pf_manage_matrix.c		\
			pf_get_start_idx.c		\
			pf_calc_edge_ngb.c		\
			pf_calc_corn_ngb.c		\
			pf_calc_middle_ngb.c

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




