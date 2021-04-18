/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:25:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 19:07:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

int	pf_manage_matrix(int **matrix, int dim[2], int idx[3])
{
	t_cell_lst	**lst;

	lst = calloc(2, sizeof(t_cell_lst *));
	if (!lst)
		return (MALLOC_ERR_CODE);
	lst[OPTIONS] = pf_lst_new(idx[I_START]);
	idx[I_LOW] = idx[I_START];
	while (lst[OPTIONS])
	{
		pf_print_matrix(matrix[DIST], dim, idx, lst);
		idx[I_LOW] = pf_get_low_idx(matrix[DIST], lst[OPTIONS]);
		lst[OPTIONS] = pf_lst_del_one(lst[OPTIONS], idx[I_LOW]);
		if (idx[I_LOW] == idx[I_END])
		{
			lst[PATH] = pf_get_path(matrix[PARENTS], idx);
			pf_print_matrix(matrix[DIST], dim, idx, lst);
			pf_lst_free(lst[OPTIONS]);
			pf_lst_free(lst[PATH]);
			return (pf_multi_free(SUCCESS, 1, lst));
		}
		pf_calc_ngb(matrix, dim, idx, &lst[OPTIONS]);
	}
	pf_lst_free(lst[OPTIONS]);
	return (pf_multi_free(IMPOSSIBLE, 1, lst));
}
