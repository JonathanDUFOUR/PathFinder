/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:25:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 10:53:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_manage_matrix(int *matrix, uint32_t dim[2])
{
	uint32_t	idx[3];
	int			debug;

	debug = 1;
	idx[I_START] = pf_get_start_idx(matrix);
	idx[I_END] = pf_get_end_idx(matrix);
	idx[I_LOW] = idx[I_START];
	while (pf_calc_dist(dim, idx[I_LOW], idx[I_END]) > 1)
	{
		pf_calc_ngb(matrix, dim, idx);
		idx[I_LOW] = pf_get_low_idx(matrix, dim);
		pf_print_matrix(matrix, dim);
		pf_pause();
		printw("Managing matrix, in loop for the %d time\n", debug++);
	}
}
