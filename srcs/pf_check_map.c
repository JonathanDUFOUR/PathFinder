/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:19:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 22:03:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

int	pf_check_map(char *map, size_t dim[2])
{
	register char	*p;

	dim[H] = 0;
	dim[W] = 0;
	p = map;
	while (*map)
	{
		while (*p && *p != '\n')
			if (!(pf_strchr(MAP_CHARS, *p++)))
				return (MAP_ERR_CODE);
		if (!(dim[W]))
			dim[W] = p - map;
		else if (dim[W] != (size_t)(p - map))
			return (MAP_ERR_CODE);
		map = ++p;
		++(dim[H]);
	}
	return (SUCCESS);
}
