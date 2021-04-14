/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:38:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/13 08:23:24 by jodufour         ###   ########.fr       */
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
			ret = pf_solve(av + 1);
			if (ret != SUCCESS)
				pf_err_msg(ret);
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
