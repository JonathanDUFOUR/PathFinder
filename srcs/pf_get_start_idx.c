/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_start_idx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:31:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 22:03:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

uint32_t	pf_get_start_idx(int *matrix)
{
	int const	*start = matrix;

	while (*start != M_START)
		++start;
	return (start - matrix);
}
