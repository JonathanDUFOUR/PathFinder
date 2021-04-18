/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:33:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 17:39:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "pathfinder.h"

int	pf_solve(char const *file)
{
	char	*map;
	int		*matrix;
	int		*parents;
	int		dim[2];
	int		idx[3];
	int		ret;

	map = pf_get_map(file);
	if (!map)
		return (MALLOC_ERR_CODE);
	if (pf_check_map(map, dim) != SUCCESS)
		return (MAP_ERR_CODE);
	map = pf_str_rm_ws(map);
	matrix = pf_get_matrix(map, dim, idx);
	parents = calloc(dim[H] * dim[W], sizeof(int));
	if (!parents)
		return (MALLOC_ERR_CODE);
	pf_print_matrix(matrix, dim, idx, NULL, NULL);
	pf_pause();
	ret = pf_manage_matrix(matrix, dim, idx, parents);
	free(map);
	free(matrix);
	free(parents);
	return (ret);
}
