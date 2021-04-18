/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:33:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 19:04:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "pathfinder.h"

int	pf_solve(char const *file)
{
	char	*map;
	int		**matrix;
	int		dim[2];
	int		idx[3];
	int		ret;

	map = pf_get_map(file);
	if (!map)
		return (MALLOC_ERR_CODE);
	if (pf_check_map(map, dim) != SUCCESS)
		return (MAP_ERR_CODE);
	map = pf_str_rm_ws(map);
	matrix = malloc(2 * sizeof(int *));
	if (!matrix)
		return (pf_multi_free(MALLOC_ERR_CODE, 1, map));
	matrix[DIST] = pf_get_matrix(map, dim, idx);
	if (!matrix[DIST])
		return (pf_multi_free(MALLOC_ERR_CODE, 2, map, matrix));
	matrix[PARENTS] = calloc(dim[H] * dim[W], sizeof(int));
	if (!matrix[PARENTS])
		return (pf_multi_free(MALLOC_ERR_CODE, 3, map, matrix[DIST], matrix));
	pf_print_matrix(matrix[DIST], dim, idx, NULL);
	pf_pause();
	ret = pf_manage_matrix(matrix, dim, idx);
	return (pf_multi_free(ret, 4, map, matrix[DIST], matrix[PARENTS], matrix));
}
