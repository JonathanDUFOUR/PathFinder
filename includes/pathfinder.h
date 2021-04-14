/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:48:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 20:40:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDER_H
# define PATHFINDER_H

# include <sys/types.h>

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

enum	e_std_fd
{
	STDIN,
	STDOUT,
	STDERR
};

enum	e_colors
{
	START_COLOR = 1,
	END_COLOR,
	OBSTACLE_COLOR,
	EMPTY_COLOR,
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
	TRUE_PATH,
	ERR_MSG
};

enum	e_dimensions
{
	HEIGHT,
	WIDTH
};

int		pf_solve(char **inputs);
int		pf_check_map(char *map, size_t dim[2]);
char	*pf_get_map(char const *file);
char	*pf_strjoin(char const *s1, char const *s2);
char	*pf_strdup(char const *s);
void	pf_setup(void);
void	pf_pause(void);
void	pf_putendl(char const *s, int const fd);
void	pf_err_msg(int errCode);
void	pf_print_map(char *map);
void	pf_print_dim(size_t dim[2]);
void	pf_wait_quit(void);
size_t	pf_strlen(char const *s);

#endif
