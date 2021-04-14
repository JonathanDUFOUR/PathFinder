/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:36:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 21:47:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_print_matrix(int *matrix, size_t dim[2])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dim[HEIGHT])
	{
		j = 0;
		while (j < dim[WIDTH])
		{
			mvprintw(dim[HEIGHT] + i + 2, (j * 3), "%d", matrix[i * dim[WIDTH] + j]);
			++j;
		}
		++i;
	}
	refresh();
}
