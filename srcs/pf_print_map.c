/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:32:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 08:12:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

static void	pf_print_obstacles(char **map)
{
	attron(COLOR_PAIR(OBSTACLE));
	while (**map == 'X')
	{
		printw("X ");
		++(*map);
	}
	attroff(COLOR_PAIR(OBSTACLE));
}

static void	pf_print_empty(char **map)
{
	attron(COLOR_PAIR(EMPTY));
	while (**map == ' ')
	{
		printw("  ");
		++(*map);
	}
	attroff(COLOR_PAIR(EMPTY));
}

static void	pf_print_start(char **map)
{
	attron(COLOR_PAIR(START));
	while (**map == 'S')
	{
		printw("S ");
		++(*map);
	}
	attroff(COLOR_PAIR(START));
}

static void	pf_print_line(char **map)
{
	while (**map && **map != '\n')
	{
		pf_print_obstacles(map);
		pf_print_empty(map);
		pf_print_start(map);
	}
}

void		pf_print_map(char *map)
{
	int	i;

	i = 0;
	while (*map)
	{
		move(i++, 0);
		pf_print_line(&map);
		if (*map)
			++map;
	}
	refresh();
}
