/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:17:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 16:37:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"
#include <stdlib.h>

t_cell_lst	*pf_lst_add_back(t_cell_lst *lst, int idx)
{
	t_cell_lst	*back;
	t_cell_lst	*p;

	if (!lst)
		return (pf_lst_new(idx));
	back = pf_lst_new(idx);
	if (!back)
	{
		pf_lst_free(lst);
		return (NULL);
	}
	p = lst;
	while (p->next)
		p = p->next;
	p->next = back;
	return (lst);
}
