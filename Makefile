# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:36:42 by jodufour          #+#    #+#              #
#    Updated: 2021/04/18 19:02:45 by jodufour         ###   ########.fr        #
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
			pf_ret_msg.c			\
			pf_get_map.c			\
			pf_lst_new.c			\
			pf_get_path.c			\
			pf_lst_free.c			\
			pf_calc_ngb.c			\
			pf_calc_dist.c			\
			pf_str_rm_ws.c			\
			pf_wait_next.c			\
			pf_wait_quit.c			\
			pf_print_map.c			\
			pf_print_dim.c			\
			pf_check_map.c			\
			pf_calc_t_ngb.c			\
			pf_calc_b_ngb.c			\
			pf_calc_l_ngb.c			\
			pf_calc_r_ngb.c			\
			pf_get_matrix.c			\
			pf_multi_free.c			\
			pf_get_low_idx.c		\
			pf_lst_del_one.c		\
			pf_lst_add_back.c		\
			pf_print_matrix.c		\
			pf_print_parents.c		\
			pf_print_new_map.c		\
			pf_manage_matrix.c		\
			pf_calc_edge_ngb.c		\
			pf_calc_corn_ngb.c		\
			pf_lst_is_in_list.c		\
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




