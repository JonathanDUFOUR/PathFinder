/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:36:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 10:52:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

static void	pf_print_cell(int cell)
{
	if (cell == M_EMPTY)
		attron(COLOR_PAIR(EMPTY_COLOR));
	else if (cell == M_START)
		attron(COLOR_PAIR(START_COLOR));
	else if (cell == M_END)
		attron(COLOR_PAIR(END_COLOR));
	else if (cell == M_OBSTACLE)
		attron(COLOR_PAIR(OBSTACLE_COLOR));
	else
		attron(COLOR_PAIR(PATH_COLOR));
	printw("% *d", 3, cell);
	attroff(COLOR_PAIR(EMPTY_COLOR));
	attroff(COLOR_PAIR(START_COLOR));
	attroff(COLOR_PAIR(END_COLOR));
	attroff(COLOR_PAIR(OBSTACLE_COLOR));
	attroff(COLOR_PAIR(PATH_COLOR));
}

void	pf_print_matrix(int *matrix, uint32_t dim[2])
{
	uint32_t	i;
	uint32_t	j;
	int			cell;

	i = 0;
	while (i < dim[H])
	{
		j = 0;
		while (j < dim[W])
		{
			cell = matrix[i * dim[W] + j];
			pf_print_cell(cell);
			++j;
		}
		printw("\n");
		++i;
	}
	refresh();
}
