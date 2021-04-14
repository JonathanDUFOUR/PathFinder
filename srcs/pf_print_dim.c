/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_dim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:56:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 22:04:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include "pathfinder.h"

void	pf_print_dim(size_t dim[2])
{
	printw("\nHEIGHT == %lu", dim[H]);
	printw("\nWIDTH  == %lu", dim[W]);
	refresh();
}
