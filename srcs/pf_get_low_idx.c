/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_low_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:59:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 22:27:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

uint32_t	pf_get_low_idx(int *matrix, uint32_t dim[2])
{
	uint32_t	idx;
	uint32_t	i;

	idx = 0;
	i = 0;
	while (i < (dim[H] * dim[W]))
	{
		if (matrix[i] > 0)
		{
			if (!idx || (matrix[i] < matrix[idx]))
				idx = i;
		}
		++i;
	}
	return (idx);
}
