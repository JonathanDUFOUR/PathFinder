/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:25:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 02:11:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

int	pf_manage_matrix(int *matrix, uint32_t dim[2], uint32_t idx[3],
	uint32_t *parents)
{
	t_cell_lst	*options;
	t_cell_lst	*path;

	options = pf_lst_new(idx[I_START]);
	idx[I_LOW] = idx[I_START];
	while (options)
	{
		pf_print_matrix(matrix, dim, idx, options, NULL);
		napms(10);
		idx[I_LOW] = pf_get_low_idx(matrix, options);
		options = pf_lst_del_one(options, idx[I_LOW]);
		if (idx[I_LOW] == idx[I_END])
		{
			path = pf_get_path(parents, idx);
			pf_print_matrix(matrix, dim, idx, options, path);
			printw("Solved\n");
			pf_lst_free(options);
			pf_lst_free(path);
			return (SUCCESS);
		}
		pf_calc_ngb(matrix, dim, idx, &options, parents);
	}
	pf_lst_free(options);
	return (IMPOSSIBLE);
}
