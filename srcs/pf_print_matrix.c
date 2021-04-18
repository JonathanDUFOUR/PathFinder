/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:36:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 02:11:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

static void	pf_print_cell(int cell, uint32_t i, uint32_t idx[3],
	t_cell_lst *options, t_cell_lst *path)
{
	if (i == idx[I_START])
		attron(COLOR_PAIR(START_COLOR));
	else if (i == idx[I_END])
		attron(COLOR_PAIR(END_COLOR));
	else if (cell == -1)
		attron(COLOR_PAIR(OBSTACLE_COLOR));
	else if (!cell)
		attron(COLOR_PAIR(EMPTY_COLOR));
	else if (pf_lst_is_in_list(options, i))
		attron(COLOR_PAIR(OPTIONS_COLOR));
	else if (pf_lst_is_in_list(path, i))
		attron(COLOR_PAIR(FIND_COLOR));
	else
		attron(COLOR_PAIR(PATH_COLOR));
	printw("  ");
	attroff(COLOR_PAIR(START_COLOR));
	attroff(COLOR_PAIR(END_COLOR));
	attroff(COLOR_PAIR(OBSTACLE_COLOR));
	attroff(COLOR_PAIR(EMPTY_COLOR));
	attroff(COLOR_PAIR(OPTIONS_COLOR));
	attroff(COLOR_PAIR(FIND_COLOR));
	attroff(COLOR_PAIR(PATH_COLOR));
}

void	pf_print_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst *options, t_cell_lst *path)
{
	uint32_t	i;
	uint32_t	size;
	int			cell;

	erase();
	i = 0;
	size = dim[H] * dim[W];
	while (i < size)
	{
		cell = matrix[i];
		pf_print_cell(cell, i, idx, options, path);
		if (!(++i % dim[W]))
			printw("\n");
	}
	refresh();
}
