/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_t_ngb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:32:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 19:25:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_t_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst *options)
{
	int	s_dist;
	int	e_dist;

	s_dist = pf_calc_dist(dim, idx[I_START], idx[I_LOW] - dim[W]);
	printw("Top neighbour -> s_dist for matrix[%u] == %d\n",
		idx[I_LOW] - dim[W], s_dist);
	e_dist = pf_calc_dist(dim, idx[I_END], idx[I_LOW] - dim[W]);
	printw("Top neighbour -> e_dist for matrix[%u] == %d\n",
		idx[I_LOW] - dim[W], e_dist);
	matrix[idx[I_LOW] - dim[W]] = s_dist + e_dist;
	pf_lst_add_back(options, idx[I_LOW] - dim[W]);
}
