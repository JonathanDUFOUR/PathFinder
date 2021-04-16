/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:25:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 00:59:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_manage_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3])
{
	t_cell_lst	*options;
	t_cell_lst	*path;
	int			debug;

	debug = 1;
	options = pf_lst_new(idx[I_START]);
	idx[I_LOW] = idx[I_START];
	pf_calc_ngb(matrix, dim, idx, options);
	options = pf_lst_del_one(options, idx[I_START]);
	while (pf_calc_dist(dim, idx[I_LOW], idx[I_END]) > 1 && options)
	{
		printw("Managing matrix, in loop for the %d time\n", debug++);
		pf_print_matrix(matrix, dim, idx, options, NULL);
		pf_pause();
		idx[I_LOW] = pf_get_low_idx(matrix, options);
		options = pf_lst_del_one(options, idx[I_LOW]);
		pf_calc_ngb(matrix, dim, idx, options);
	}
	if (pf_calc_dist(dim, idx[I_LOW], idx[I_END]) == 1)
	{
		printw("Solved :\n");
		path = NULL;
		path = pf_get_path(matrix, dim, idx);
		pf_print_matrix(matrix, dim, idx, options, path);
		pf_pause();
		pf_lst_free(path);
	}
	else
	{
		printw("Impossible\n");
		pf_pause();
	}
	pf_lst_free(options);
}
