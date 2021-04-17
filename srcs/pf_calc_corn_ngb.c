/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_corn_ngb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:30:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 20:00:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_corn_tl_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options)
{
	if (!(matrix[idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options);
	if (!(matrix[idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options);
}

void	pf_calc_corn_tr_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options)
{
	if (!(matrix[idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options);
	if (!(matrix[idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options);
}

void	pf_calc_corn_bl_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options)
{
	if (!(matrix[idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options);
	if (!(matrix[idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options);
}

void	pf_calc_corn_br_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options)
{
	if (!(matrix[idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options);
	if (!(matrix[idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options);
}
