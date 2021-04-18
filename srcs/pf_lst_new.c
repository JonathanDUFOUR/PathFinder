/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:05:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 16:37:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"
#include <stdlib.h>

t_cell_lst	*pf_lst_new(int idx)
{
	t_cell_lst	*lst;

	lst = malloc(sizeof(t_cell_lst));
	if (!lst)
		return (NULL);
	lst->idx = idx;
	lst->next = NULL;
	return (lst);
}
