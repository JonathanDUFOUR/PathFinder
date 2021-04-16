/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:17:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 14:26:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"
#include <stdlib.h>

t_path	*pf_lst_add_back(t_path *path, uint32_t idx)
{
	t_path	*back;
	t_path	*p;

	back = pf_lst_new(idx);
	if (!back)
		return (NULL);
	p = path;
	while (p->next)
		p = p->next;
	p->next = back;
	return (path);
}
