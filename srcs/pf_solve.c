/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:33:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 08:45:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

int	pf_solve(char **inputs)
{
	char	*map;

	while (*inputs)
	{
		map = pf_get_map(*inputs);
		if (!map)
			return (MAP_ERR_CODE);
		erase();
		pf_print_map(map);
		refresh();
		free(map);
		++inputs;
		pf_pause();
	}
	return (SUCCESS);
}
