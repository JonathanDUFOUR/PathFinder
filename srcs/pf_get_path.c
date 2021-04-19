/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:57:57 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/19 11:16:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

t_cell_lst	*pf_get_path(int *parents, int idx[3])
{
	t_cell_lst	*path;

	path = NULL;
	while (idx[I_LOW] != idx[I_START])
	{
		path = pf_lst_add_back(path, idx[I_LOW]);
		if (!path)
			return (NULL);
		idx[I_LOW] = parents[idx[I_LOW]];
	}
	return (path);
}
