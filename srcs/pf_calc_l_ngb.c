/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_l_ngb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:39:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 20:08:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

void	pf_calc_l_ngb(int *matrix, uint32_t dim[2], uint32_t idx[3],
	t_cell_lst **options)
{
	int	s_dist;
	int	e_dist;

	s_dist = pf_calc_dist(dim, idx[I_START], idx[I_LOW] - 1);
	e_dist = pf_calc_dist(dim, idx[I_END], idx[I_LOW] - 1);
	matrix[idx[I_LOW] - 1] = s_dist + e_dist;
	*options = pf_lst_add_back(*options, idx[I_LOW] - 1);
}
