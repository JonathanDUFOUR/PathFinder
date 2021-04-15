/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_dim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:56:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/15 22:41:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_print_dim(uint32_t dim[2])
{
	printw("HEIGHT == %u\n", dim[H]);
	printw("WIDTH  == %u\n", dim[W]);
	refresh();
}
