/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:38:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 21:07:24 by jodufour         ###   ########.fr       */
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
			while (ac - 1)
			{
				ret = pf_solve(*(++av));
				if (ret != SUCCESS)
					pf_err_msg(ret);
				--ac;
			}
		else
			pf_err_msg(AC_ERR_CODE);
	}
	else
		pf_err_msg(COLORS_ERR_CODE);
	pf_wait_quit();
	endwin();
	return (ret);
}
