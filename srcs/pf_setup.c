/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:56:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 09:21:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_setup(void)
{
	start_color();
	init_pair(START_COLOR, COLOR_BLACK, COLOR_YELLOW);
	init_pair(END_COLOR, COLOR_BLACK, COLOR_GREEN);
	init_pair(OBSTACLE_COLOR, COLOR_BLACK, COLOR_WHITE);
	init_pair(EMPTY_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(PATH_COLOR, COLOR_BLACK, COLOR_RED);
	init_pair(FIND_COLOR, COLOR_BLACK, COLOR_CYAN);
	init_pair(ERR_MSG_COLOR, COLOR_RED, COLOR_BLACK);
	curs_set(0);
	cbreak();
	noecho();
	nodelay(stdscr, FALSE);
	scrollok(stdscr, TRUE);
}
