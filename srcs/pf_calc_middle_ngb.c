/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_middle_ngb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:12:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 00:36:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_middle_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options, uint32_t *parents)
{
	if (!(matrix[idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options, parents);
}
