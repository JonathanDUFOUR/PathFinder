/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:38:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 19:00:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"
#include <ncurses.h>

int	main(int ac, char **av)
{
	int	ret;

	initscr();
	if (has_colors() == TRUE)
	{
		pf_setup();
		if (ac > 1)
		{
			while (ac - 1)
			{
				ret = pf_solve(*(++av));
				pf_ret_msg(ret);
				if ((--ac) - 1)
					pf_wait_next();
			}
		}
		else
			pf_ret_msg(AC_ERR_CODE);
	}
	else
		pf_ret_msg(COLORS_ERR_CODE);
	pf_wait_quit();
	endwin();
	return (ret);
}
