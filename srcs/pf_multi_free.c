/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_multi_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:39:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/18 18:50:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>

int	pf_multi_free(int ret, size_t n, ...)
{
	void	*dent;
	va_list	va;
	size_t	i;

	va_start(va, n);
	i = 0;
	while (i++ < n)
	{
		dent = va_arg(va, void *);
		free(dent);
	}
	va_end(va);
	return (ret);
}
