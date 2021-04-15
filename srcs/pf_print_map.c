/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:32:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 22:41:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

static void	pf_print_start(char **map)
{
	attron(COLOR_PAIR(START_COLOR));
	while (**map == MAP_CHARS[START])
	{
		printw("%c ", MAP_CHARS[START]);
		++(*map);
	}
	attroff(COLOR_PAIR(START_COLOR));
}

static void	pf_print_end(char **map)
{
	attron(COLOR_PAIR(END_COLOR));
	while (**map == MAP_CHARS[END])
	{
		printw("%c ", MAP_CHARS[END]);
		++(*map);
	}
	attroff(COLOR_PAIR(END_COLOR));
}

static void	pf_print_obstacles(char **map)
{
	attron(COLOR_PAIR(OBSTACLE_COLOR));
	while (**map == MAP_CHARS[OBSTACLE])
	{
		printw("%c ", MAP_CHARS[OBSTACLE]);
		++(*map);
	}
	attroff(COLOR_PAIR(OBSTACLE_COLOR));
}

static void	pf_print_empty(char **map)
{
	attron(COLOR_PAIR(EMPTY_COLOR));
	while (**map == MAP_CHARS[EMPTY])
	{
		printw("%c ", MAP_CHARS[EMPTY]);
		++(*map);
	}
	attroff(COLOR_PAIR(EMPTY_COLOR));
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
			pf_print_start(&map);
			pf_print_end(&map);
			pf_print_obstacles(&map);
			pf_print_empty(&map);
		}
		if (*map)
			++map;
	}
	printw("\n");
	refresh();
}
