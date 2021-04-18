/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:20:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 17:36:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

static int	*pf_malloc_matrix(int **matrix, int dim[2])
{
	*matrix = malloc (dim[H] * dim[W] * sizeof(int));
	if (!(*matrix))
		return (NULL);
	return (*matrix);
}

int	*pf_get_matrix(char *map, int dim[2], int idx[3])
{
	int	*matrix;
	int	i;
	int	size;

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
