/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:20:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 17:11:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

static int	*pf_malloc_matrix(int **matrix, uint32_t dim[2])
{
	*matrix = malloc (dim[H] * dim[W] * sizeof(int));
	if (!(*matrix))
		return (NULL);
	return (*matrix);
}

int	*pf_get_matrix(char *map, uint32_t dim[2], uint32_t idx[3])
{
	int			*matrix;
	uint32_t	i;
	uint32_t	size;

	if (!(pf_malloc_matrix(&matrix, dim)))
		return (NULL);
	i = 0;
	size = dim[H] * dim[W];
	while (i < size)
	{
		if (map[i] == MAP_CHARS[OBSTACLE])
			matrix[i] = -1;
		else
		{
			if (map[i] == MAP_CHARS[START])
				idx[I_START] = i;
			else if (map[i] == MAP_CHARS[END])
				idx[I_END] = i;
			else
				matrix[i] = 0;
		}
		++i;
	}
	matrix[idx[I_START]] = pf_calc_dist(dim, idx[I_START], idx[I_END]);
	return (matrix);
}
