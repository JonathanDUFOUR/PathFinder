/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:36:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 20:38:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

int	pf_calc_dist(uint32_t dim[2], uint32_t idx1, uint32_t idx2)
{
	uint32_t	x_dist;
	uint32_t	y_dist;
	uint32_t	a;
	uint32_t	b;

	a = idx1 % dim[W];
	b = idx2 % dim[W];
	if (a < b)
		y_dist = b - a;
	else
		y_dist = a - b;
	a = idx1 / dim[W];
	b = idx2 / dim[W];
	if (a < b)
		x_dist = b - a;
	else
		x_dist = a - b;
	return (x_dist + y_dist);
}
