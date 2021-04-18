/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_dim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:56:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 16:38:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "pathfinder.h"

void	pf_print_dim(int dim[2])
{
	printw("HEIGHT == %d\n", dim[H]);
	printw("WIDTH  == %d\n", dim[W]);
	refresh();
}
