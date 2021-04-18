/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_r_ngb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:40:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 17:03:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_r_ngb(int *matrix, int dim[2], int idx[3],
	t_cell_lst **options, int *parents)
{
	int	s_dist;
	int	e_dist;

	parents[idx[I_LOW] + 1] = idx[I_LOW];
	s_dist = matrix[I_LOW] + 1;
	e_dist = pf_calc_dist(dim, idx[I_END], idx[I_LOW] + 1);
	matrix[idx[I_LOW] + 1] = s_dist + e_dist;
	*options = pf_lst_add_back(*options, idx[I_LOW] + 1);
}
