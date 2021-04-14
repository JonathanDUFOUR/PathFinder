/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:56:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 08:15:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_setup()
{
	start_color();
	init_pair(START, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(END, COLOR_GREEN, COLOR_BLACK);
	init_pair(OBSTACLE, COLOR_WHITE, COLOR_WHITE);
	init_pair(EMPTY, COLOR_BLACK, COLOR_BLACK);
	init_pair(PATH, COLOR_RED, COLOR_BLACK);
	init_pair(TRUE_PATH, COLOR_CYAN, COLOR_BLACK);
	init_pair(ERR_MSG, COLOR_RED, COLOR_BLACK);
	curs_set(0);
	cbreak();
	noecho();
	nodelay(stdscr, FALSE);
	scrollok(stdscr, TRUE);
}
