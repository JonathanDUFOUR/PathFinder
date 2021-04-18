/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wait_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:01:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 19:02:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

void	pf_wait_next(void)
{
	int	ch;

	printw("Press N to solve the Next map\n");
	while (1)
	{
		ch = getch();
		if (ch == 'n' || ch == 'N')
			break ;
	}
	refresh();
}
