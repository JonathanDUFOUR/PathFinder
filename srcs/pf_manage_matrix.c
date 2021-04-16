/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:25:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 14:44:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_manage_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3])
{
	t_path		*path;
	int			debug;

	debug = 1;
	path = pf_lst_new(idx[I_START]);
	idx[I_LOW] = idx[I_START];
	while (pf_calc_dist(dim, idx[I_LOW], idx[I_END]) > 1)
	{
		idx[I_LOW] = pf_get_low_idx(path);
		pf_calc_ngb(matrix, dim, idx);
		pf_print_matrix(matrix, dim, idx);
		pf_pause();
		printw("Managing matrix, in loop for the %d time\n", debug++);
	}
}
