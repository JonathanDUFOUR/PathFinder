/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:36:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 18:32:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

int	pf_calc_dist(int dim[2], int idx1, int idx2)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dist;

	x1 = idx1 % dim[W];
	x2 = idx2 % dim[W];
	y1 = idx1 / dim[W];
	y2 = idx2 / dim[W];
	dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return (dist);
}
