/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:19:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/16 15:33:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

char	*pf_strjoin(char const *s1, char const *s2)
{
	char	*output;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (pf_strdup(s2));
	if (!s2)
		return (pf_strdup(s1));
	output = malloc((pf_strlen(s1) + pf_strlen(s2) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = 0;
	return (output);
}
