/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_corn_ngb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:30:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 19:04:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_corn_tl_ngb(int **matrix, int dim[2], int idx[3],
	t_cell_lst **options)
{
	if (!(matrix[DIST][idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options);
	if (!(matrix[DIST][idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options);
}

void	pf_calc_corn_tr_ngb(int **matrix, int dim[2], int idx[3],
	t_cell_lst **options)
{
	if (!(matrix[DIST][idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options);
	if (!(matrix[DIST][idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options);
}

void	pf_calc_corn_bl_ngb(int **matrix, int dim[2], int idx[3],
	t_cell_lst **options)
{
	if (!(matrix[DIST][idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options);
	if (!(matrix[DIST][idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options);
}

void	pf_calc_corn_br_ngb(int **matrix, int dim[2], int idx[3],
	t_cell_lst **options)
{
	if (!(matrix[DIST][idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options);
	if (!(matrix[DIST][idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options);
}
