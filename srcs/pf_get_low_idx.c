/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_low_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:59:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 16:36:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

int	pf_get_low_idx(int *matrix, t_cell_lst *options)
{
	int	l_idx;

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
