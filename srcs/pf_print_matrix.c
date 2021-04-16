/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:36:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 15:22:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

static void	pf_print_cell(int cell, uint32_t i, uint32_t idx[3])
{
	if (i == idx[I_START])
		attron(COLOR_PAIR(START_COLOR));
	else if (i == idx[I_END])
		attron(COLOR_PAIR(END_COLOR));
	else if (cell == -1)
		attron(COLOR_PAIR(OBSTACLE_COLOR));
	else if (!cell)
		attron(COLOR_PAIR(EMPTY_COLOR));
	else
		attron(COLOR_PAIR(PATH_COLOR));
	printw("% *d", 3, cell);
	attroff(COLOR_PAIR(EMPTY_COLOR));
	attroff(COLOR_PAIR(START_COLOR));
	attroff(COLOR_PAIR(END_COLOR));
	attroff(COLOR_PAIR(OBSTACLE_COLOR));
	attroff(COLOR_PAIR(PATH_COLOR));
}

void	pf_print_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3])
{
	uint32_t	i;
	uint32_t	size;
	int			cell;

	i = 0;
	size = dim[H] * dim[W];
	while (i < size)
	{
		cell = matrix[i];
		pf_print_cell(cell, i, idx);
		if (!(++i % dim[W]))
			printw("\n");
	}
	refresh();
}
