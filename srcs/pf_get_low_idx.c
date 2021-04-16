/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_low_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:59:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 15:20:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

uint32_t	pf_get_low_idx(t_path *path)
{
	uint32_t	low_idx;
	int			low_val;

	low_idx = path->idx;
	low_val = path->value;
	while (path->next)
	{
		if (1)
			;
		path = path->next;
	}
	return (low_idx);
}
