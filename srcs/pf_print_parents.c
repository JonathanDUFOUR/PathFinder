/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_parents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:18:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 22:23:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_print_parents(uint32_t *parents, uint32_t dim[2])
{
	uint32_t	size;
	uint32_t	i;

	size = dim[H] * dim[W];
	i = 0;
	while (i < size)
	{
		printw("% *u", 4, parents[i]);
		++i;
		if (!(i % dim[W]))
			printw("\n");
	}
}
