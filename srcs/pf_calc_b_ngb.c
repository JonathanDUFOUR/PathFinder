/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_b_ngb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:38:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 23:02:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_b_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3])
{
	int	s_dist;
	int	e_dist;

	s_dist = pf_calc_dist(dim, idx[I_START], idx[I_LOW] + dim[W]);
	printw("s_dist for matrix[%u] == %d\n", idx[I_LOW] + dim[W], s_dist);
	e_dist = pf_calc_dist(dim, idx[I_END], idx[I_LOW] + dim[W]);
	printw("e_dist for matrix[%u] == %d\n", idx[I_LOW] + dim[W], e_dist);
	matrix[idx[I_LOW] + dim[W]] = s_dist + e_dist;
}
