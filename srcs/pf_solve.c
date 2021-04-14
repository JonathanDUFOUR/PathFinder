/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:33:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 20:59:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "pathfinder.h"

int	pf_solve(char **inputs)
{
	char		*map;
	int			*matrix;
	size_t		dim[2];

	while (*inputs)
	{
		map = pf_get_map(*inputs);
		if (!map || pf_check_map(map, dim) != SUCCESS)
			return (MAP_ERR_CODE);
		pf_print_map(map);
		pf_print_dim(dim);
		refresh();
		pf_pause();
		erase();
		free(map);
		++inputs;
	}
	return (SUCCESS);
}
