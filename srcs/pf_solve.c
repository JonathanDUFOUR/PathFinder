/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:33:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 00:46:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "pathfinder.h"

int	pf_solve(char const *file)
{
	char		*map;
	int			*matrix;
	uint32_t	dim[2];
	uint32_t	idx[3];

	map = pf_get_map(file);
	if (!map || pf_check_map(map, dim) != SUCCESS)
		return (MAP_ERR_CODE);
	pf_print_map(map);
	pf_print_dim(dim);
	pf_pause();
	map = pf_str_rm_ws(map);
	matrix = pf_get_matrix(map, dim, idx);
	pf_print_matrix(matrix, dim, idx, NULL, NULL);
	pf_pause();
	pf_manage_matrix(matrix, dim, idx);
	erase();
	free(map);
	free(matrix);
	return (SUCCESS);
}
