/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_ngb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:55:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 20:09:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_calc_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
t_cell_lst **options)
{
	uint32_t	x;
	uint32_t	y;

	x = idx[I_LOW] / dim[W];
	y = idx[I_LOW] % dim[W];
	if (!x && !y)
		pf_calc_corn_tl_ngb(matrix, dim, idx, options);
	else if (!x && y == (dim[W] - 1))
		pf_calc_corn_tr_ngb(matrix, dim, idx, options);
	else if (!x)
		pf_calc_edge_t_ngb(matrix, dim, idx, options);
	else if (x == (dim[H] - 1) && !y)
		pf_calc_corn_bl_ngb(matrix, dim, idx, options);
	else if (x == (dim[H] - 1) && y == (dim[W] - 1))
		pf_calc_corn_br_ngb(matrix, dim, idx, options);
	else if (x == (dim[H] - 1))
		pf_calc_edge_b_ngb(matrix, dim, idx, options);
	else if (!y)
		pf_calc_edge_l_ngb(matrix, dim, idx, options);
	else if (y == (dim[W] - 1))
		pf_calc_edge_r_ngb(matrix, dim, idx, options);
	else
		pf_calc_middle_ngb(matrix, dim, idx, options);
}
