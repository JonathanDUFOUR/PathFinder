/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:00:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/07 23:25:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pathfinder.h"

void	pf_putendl(char const *s, int const fd)
{
	write(fd, s, pf_strlen(s));
	write(fd, "\n", 1);
}
