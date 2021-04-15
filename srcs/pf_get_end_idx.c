/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_end_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:50:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 22:55:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

uint32_t	pf_get_end_idx(int *matrix)
{
	int const	*end = matrix;

	while (*end != M_END)
		++end;
	return (end - matrix);
}
