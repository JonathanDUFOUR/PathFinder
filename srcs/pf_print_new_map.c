/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_new_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:45:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 15:56:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_print_new_map(char *map)
{
	while (*map)
	{
		if (*map == MAP_CHARS[START])
			attron(COLOR_PAIR(START_COLOR));
		else if (*map == MAP_CHARS[END])
			attron(COLOR_PAIR(END_COLOR));
		else if (*map == MAP_CHARS[OBSTACLE])
			attron(COLOR_PAIR(OBSTACLE_COLOR));
		else
			attron(COLOR_PAIR(EMPTY_COLOR));
		printw("% *c", 2, *map);
		attroff(COLOR_PAIR(START_COLOR));
		attroff(COLOR_PAIR(END_COLOR));
		attroff(COLOR_PAIR(OBSTACLE_COLOR));
		attroff(COLOR_PAIR(EMPTY_COLOR));
		++map;
	}
	printw("\n");
}
