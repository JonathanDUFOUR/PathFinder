/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:22:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 19:24:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

void	pf_lst_free(t_cell_lst *lst)
{
	t_cell_lst	*dent;

	while (lst)
	{
		dent = lst;
		lst = lst->next;
		free(dent);
	}
}
