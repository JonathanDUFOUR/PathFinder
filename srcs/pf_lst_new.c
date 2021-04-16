/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:05:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 14:07:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"
#include <stdlib.h>

t_path	*pf_lst_new(uint32_t idx)
{
	t_path	*output;

	output = malloc(1 * sizeof(t_path));
	if (!output)
		return (NULL);
	output->idx = idx;
	output->next = NULL;
	return (output);
}
