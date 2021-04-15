/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:36:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 22:48:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_print_matrix(int *matrix, uint32_t dim[2])
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < dim[H])
	{
		j = 0;
		while (j < dim[W])
		{
			printw("% *d ", 3, matrix[i * dim[W] + j]);
			++j;
		}
		printw("\n");
		++i;
	}
	refresh();
}
