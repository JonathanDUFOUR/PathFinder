/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:54:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/13 08:55:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ncurses.h>
#include "pathfinder.h"

void	pf_err_msg(int errCode)
{
	if (errCode == COLORS_ERR_CODE)
		printw("Error: colors are not supported on your terminal");
	else
	{
		attron(COLOR_PAIR(ERR_MSG));
		if (errCode == MAP_ERR_CODE)
			printw("Error: map error");
		attroff(COLOR_PAIR(ERR_MSG));
	}
}
