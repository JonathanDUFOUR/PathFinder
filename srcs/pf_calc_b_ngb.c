/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_b_ngb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:38:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 19:04:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_b_ngb(int **matrix, int dim[2], int idx[3],
	t_cell_lst **options)
{
	int	s_dist;
	int	e_dist;

	matrix[PARENTS][idx[I_LOW] + dim[W]] = idx[I_LOW];
	s_dist = matrix[DIST][I_LOW] + 1;
	e_dist = pf_calc_dist(dim, idx[I_END], idx[I_LOW] + dim[W]);
	matrix[DIST][idx[I_LOW] + dim[W]] = s_dist + e_dist;
	*options = pf_lst_add_back(*options, idx[I_LOW] + dim[W]);
}
