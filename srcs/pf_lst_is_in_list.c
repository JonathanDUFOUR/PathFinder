/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_is_in_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:30:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 19:32:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

bool	pf_lst_is_in_list(t_cell_lst *lst, uint32_t idx)
{
	while (lst)
	{
		if (idx == lst->idx)
			return (true);
		lst = lst->next;
	}
	return (false);
}
