/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:25:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 20:20:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_manage_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3])
{
	t_cell_lst	*options;
	int			debug;

	debug = 1;
	options = pf_lst_new(idx[I_START]);
	idx[I_LOW] = idx[I_START];
	pf_calc_ngb(matrix, dim, idx, options);
	options = pf_lst_del_one(options, idx[I_START]);
	pf_print_matrix(matrix, dim, idx, options);
	printw("Managing matrix before the loop\n");
	pf_pause();
	while (pf_calc_dist(dim, idx[I_LOW], idx[I_END]) > 1)
	{
		pf_calc_ngb(matrix, dim, idx, options);
		pf_print_matrix(matrix, dim, idx, options);
		printw("Managing matrix, in loop for the %d time\n", debug++);
		pf_pause();
	}
	pf_lst_free(options);
}
