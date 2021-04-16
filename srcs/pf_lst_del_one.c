/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:21:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 21:09:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

static t_cell_lst	*pf_del_first(t_cell_lst *lst)
{
	t_cell_lst	*output;

	output = lst->next;
	free(lst);
	return (output);
}

t_cell_lst	*pf_lst_del_one(t_cell_lst *lst, uint32_t idx)
{
	t_cell_lst	*output;
	t_cell_lst	*prev;

	if (!lst)
		return (NULL);
	else if (lst->idx == idx)
		output = pf_del_first(lst);
	else
	{
		output = lst;
		prev = lst;
		lst = lst->next;
		while (lst)
		{
			if (lst->idx == idx)
			{
				prev->next = lst->next;
				free(lst);
				break ;
			}
			prev = lst;
			lst = lst->next;
		}
	}
	return (output);
}
