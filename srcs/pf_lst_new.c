/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:05:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 19:00:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"
#include <stdlib.h>

t_cell_lst	*pf_lst_new(uint32_t idx)
{
	t_cell_lst	*output;

	output = malloc(1 * sizeof(t_cell_lst));
	if (!output)
		return (NULL);
	output->idx = idx;
	output->next = NULL;
	return (output);
}
