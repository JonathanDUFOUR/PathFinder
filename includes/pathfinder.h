/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:48:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 20:21:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDER_H
# define PATHFINDER_H

# include <sys/types.h>
# include <stdint.h>

/* Remove it when all bugs are fixed */
# include <ncurses.h>

# define MAP_CHARS "SEX PF"
# define BUFF_SIZE 4096
# define OPEN_ERROR -1
# define READ_ERROR	-1

enum	e_ret_codes
{
	SUCCESS,
	COLORS_ERR_CODE,
	AC_ERR_CODE,
	STRJOIN_ERR_CODE,
	MAP_ERR_CODE
};

enum	e_colors
{
	START_COLOR = 1,
	END_COLOR,
	OBSTACLE_COLOR,
	EMPTY_COLOR,
	OPTIONS_COLOR,
	PATH_COLOR,
	FIND_COLOR,
	ERR_MSG_COLOR
};

enum	e_lements
{
	START,
	END,
	OBSTACLE,
	EMPTY,
	PATH,
	TRUE_PATH
};

enum	e_dimensions
{
	H,
	W
};

enum	e_index
{
	I_START,
	I_END,
	I_LOW
};

typedef struct s_cell_lst	t_cell_lst;

struct	s_cell_lst
{
	uint32_t	idx;
	t_cell_lst	*next;
};

int			pf_solve(char const *file);
int			pf_check_map(char *map, uint32_t dim[2]);
int			*pf_get_matrix(char *map, uint32_t dim[2], uint32_t idx[3]);
int			pf_calc_dist(uint32_t dim[2], uint32_t idx1, uint32_t idx2);
char		*pf_get_map(char const *file);
char		*pf_strjoin(char const *s1, char const *s2);
char		*pf_strdup(char const *s);
char		*pf_strchr(char const *s, char c);
char		*pf_str_rm_ws(char const *s);
void		pf_setup(void);
void		pf_pause(void);
void		pf_err_msg(int errCode);
void		pf_print_map(char *map);
void		pf_print_dim(uint32_t dim[2]);
void		pf_print_new_map(char *map);
void		pf_manage_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3]);
void		pf_print_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_corn_tl_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_corn_tr_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_corn_bl_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_corn_br_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_edge_t_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_edge_b_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_edge_r_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_edge_l_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_middle_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_t_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_b_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_l_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_calc_r_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
				t_cell_lst *options);
void		pf_lst_free(t_cell_lst *lst);
void		pf_wait_quit(void);
size_t		pf_strlen(char const *s);
uint32_t	pf_get_low_idx(int *matrix, t_cell_lst *lst);
t_cell_lst	*pf_lst_new(uint32_t idx);
t_cell_lst	*pf_lst_add_back(t_cell_lst *lst, uint32_t idx);
t_cell_lst	*pf_lst_del_one(t_cell_lst *lst, uint32_t idx);

#endif
