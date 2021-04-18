/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ret_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:54:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 18:59:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_ret_msg(int errCode)
{
	if (errCode == COLORS_ERR_CODE)
		printw("Error: colors are not supported on your terminal\n");
	else if (errCode == SUCCESS)
	{
		attron(COLOR_PAIR(SUCCESS_MSG_COLOR));
		printw("Solved !\n");
		attroff(COLOR_PAIR(SUCCESS_MSG_COLOR));
	}
	else
	{
		attron(COLOR_PAIR(ERR_MSG_COLOR));
		if (errCode == MAP_ERR_CODE)
			printw("Error: map error\n");
		else if (errCode == AC_ERR_CODE)
			printw("Error: Arguments count is invalid.\n");
		else if (errCode == MALLOC_ERR_CODE)
			printw("Error: Malloc failed\n");
		else if (errCode == IMPOSSIBLE)
			printw("No solution available\n");
		attroff(COLOR_PAIR(ERR_MSG_COLOR));
	}
}
