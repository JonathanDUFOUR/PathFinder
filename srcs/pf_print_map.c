/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:32:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 20:10:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "pathfinder.h"

static void	pf_print_obstacles(char **map)
{
	attron(COLOR_PAIR(OBSTACLE_COLOR));
	while (**map == 'X')
	{
		printw("X ");
		++(*map);
	}
	attroff(COLOR_PAIR(OBSTACLE_COLOR));
}

static void	pf_print_empty(char **map)
{
	attron(COLOR_PAIR(EMPTY_COLOR));
	while (**map == ' ')
	{
		printw("  ");
		++(*map);
	}
	attroff(COLOR_PAIR(EMPTY_COLOR));
}

static void	pf_print_start(char **map)
{
	attron(COLOR_PAIR(START_COLOR));
	while (**map == 'S')
	{
		printw("S ");
		++(*map);
	}
	attroff(COLOR_PAIR(START_COLOR));
}

static void	pf_print_end(char **map)
{
	attron(COLOR_PAIR(END_COLOR));
	while (**map == 'E')
	{
		printw("E ");
		++(*map);
	}
	attroff(COLOR_PAIR(END_COLOR));
}

void	pf_print_map(char *map)
{
	int	i;

	i = 0;
	while (*map)
	{
		move(i++, 0);
		while (*map && *map != '\n')
		{
			pf_print_obstacles(&map);
			pf_print_empty(&map);
			pf_print_start(&map);
			pf_print_end(&map);
		}
		if (*map)
			++map;
	}
	refresh();
}
