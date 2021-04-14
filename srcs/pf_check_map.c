/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:19:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 20:49:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

int	pf_check_map(char *map, size_t dim[2])
{
	register char	*p;

	dim[HEIGHT] = 0;
	dim[WIDTH] = 0;
	p = map;
	while (*map)
	{
		while (*p && *p != '\n')
			if (!(pf_strchr(MAP_CHARS, *p++)))
				return (MAP_ERR_CODE);
		if (!(dim[WIDTH]))
			dim[WIDTH] = p - map;
		else if (dim[WIDTH] != (size_t)(p - map))
			return (MAP_ERR_CODE);
		map = ++p;
		++(dim[HEIGHT]);
	}
	return (SUCCESS);
}
