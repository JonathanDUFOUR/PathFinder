/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wait_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:04:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 21:22:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

void	pf_wait_quit(void)
{
	int	ch;

	printw("Press Q to quit the ncurses window\n");
	while (1)
	{
		ch = getch();
		if (ch == 'q' || ch == 'Q')
			break ;
	}
	refresh();
}
