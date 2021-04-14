/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:48:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 08:13:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDER_H
# define PATHFINDER_H

# include <sys/types.h>
# include <ncurses.h>

# define BUFF_SIZE 4096
# define OPEN_ERROR -1
# define READ_ERROR	-1

enum	e_ret_codes
{
	SUCCESS,
	COLORS_ERR_CODE,
	AC_ERR_CODE,
	MAP_ERR_CODE
};

enum	e_std_fd
{
	STDIN,
	STDOUT,
	STDERR
};

enum	e_lements
{
	START = 1,
	END,
	OBSTACLE,
	EMPTY,
	PATH,
	TRUE_PATH,
	ERR_MSG
};

int		pf_solve(char **inputs);
char	*pf_get_map(char *file);
char	*pf_strjoin(char const *s1, char const *s2);
char	*pf_strdup(char const *s);
void	pf_setup(void);
void	pf_pause(void);
void	pf_putendl(char const *s, int const fd);
void	pf_err_msg(int errCode);
void	pf_print_map(char *map);
void	pf_wait_quit(void);
size_t	pf_strlen(char const *s);

#endif
