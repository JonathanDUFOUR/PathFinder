/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:20:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 21:34:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

int	*pf_get_matrix(char *map, size_t dim[2])
{
	int	*matrix;
	size_t	i;
	size_t	j;

	matrix = malloc (dim[HEIGHT] * dim[WIDTH] * sizeof(int));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < dim[HEIGHT])
	{
		j = 0;
		while (j < dim[WIDTH])
		{
			if (map[i * dim[WIDTH] + i + j] == MAP_CHARS[START])
				matrix[(i * dim[WIDTH]) + j] = -1;
			else if (map[i * dim[WIDTH] + i + j] == MAP_CHARS[END])
				matrix[(i * dim[WIDTH]) + j] = -2;
			else if (map[i * dim[WIDTH] + i + j] == MAP_CHARS[OBSTACLE])
				matrix[(i * dim[WIDTH]) + j] = -3;
			else if (map[i * dim[WIDTH] + i + j] == MAP_CHARS[EMPTY])
				matrix[(i * dim[WIDTH]) + j] = 0;
			++j;
		}
		++i;
	}
	return (matrix);
}
