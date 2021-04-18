/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pause.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:43:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 02:17:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

void	pf_pause(void)
{
	int	ch;

	printw("Press M to see the Magic appear :P\n");
	while (1)
	{
		ch = getch();
		if (ch == 'm' || ch == 'M')
			break ;
	}
	refresh();
}
