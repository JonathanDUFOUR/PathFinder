/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_edge_ngb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:20:47 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 22:38:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_edge_t_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options, uint32_t *parents)
{
	if (!(matrix[idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options, parents);
}

void	pf_calc_edge_b_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options, uint32_t *parents)
{
	if (!(matrix[idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options, parents);
}

void	pf_calc_edge_l_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options, uint32_t *parents)
{
	if (!(matrix[idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] + 1]))
		pf_calc_r_ngb(matrix, dim, idx, options, parents);
}

void	pf_calc_edge_r_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options, uint32_t *parents)
{
	if (!(matrix[idx[I_LOW] - dim[W]]))
		pf_calc_t_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] + dim[W]]))
		pf_calc_b_ngb(matrix, dim, idx, options, parents);
	if (!(matrix[idx[I_LOW] - 1]))
		pf_calc_l_ngb(matrix, dim, idx, options, parents);
}
