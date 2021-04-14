/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:20:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 22:03:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

int	*pf_get_matrix(char *map, size_t dim[2])
{
	int		*matrix;
	size_t	i[2];

	matrix = malloc (dim[H] * dim[W] * sizeof(int));
	if (!matrix)
		return (NULL);
	i[H] = 0;
	while (i[H] < dim[H])
	{
		i[W] = 0;
		while (i[W] < dim[W])
		{
			if (map[i[H] * dim[W] + i[H] + i[W]] == MAP_CHARS[START])
				matrix[(i[H] * dim[W]) + i[W]] = -1;
			else if (map[i[H] * dim[W] + i[H] + i[W]] == MAP_CHARS[END])
				matrix[(i[H] * dim[W]) + i[W]] = -2;
			else if (map[i[H] * dim[W] + i[H] + i[W]] == MAP_CHARS[OBSTACLE])
				matrix[(i[H] * dim[W]) + i[W]] = -3;
			else if (map[i[H] * dim[W] + i[H] + i[W]] == MAP_CHARS[EMPTY])
				matrix[(i[H] * dim[W]) + i[W]] = 0;
			++i[W];
		}
		++i[H];
	}
	return (matrix);
}
