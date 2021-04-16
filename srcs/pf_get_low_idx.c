/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_low_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:59:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 22:00:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

uint32_t	pf_get_low_idx(int *matrix, t_cell_lst *options)
{
	uint32_t	l_idx;

	if (options)
	{
		l_idx = options->idx;
		options = options->next;
		while (options)
		{
			if (matrix[options->idx] < matrix[l_idx])
				l_idx = options->idx;
			options = options->next;
		}
	}
	return (l_idx);
}
