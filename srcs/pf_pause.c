/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pause.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 08:43:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/13 08:47:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

void	pf_pause(void)
{
	int	ch;

	mvprintw(30, 0, "Paused, press C to continue\n");
	while (1)
	{
		ch = getch();
		if (ch == 'c' || ch == 'C')
			break ;
	}
	refresh();
}
