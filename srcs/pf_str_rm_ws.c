/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_rm_ws.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:38:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 15:58:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>

char	*pf_str_rm_ws(char const *s)
{
	char		*output;
	char		*p;
	char const	*dent = s;
	size_t		len;

	len = 0;
	while (*s)
		if (*s++ != '\n')
			++len;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	s = dent;
	p = output;
	while (*s)
	{
		if (*s != '\n')
			*p++ = *s;
		++s;
	}
	*p = 0;
	free((char *)dent);
	return (output);
}
