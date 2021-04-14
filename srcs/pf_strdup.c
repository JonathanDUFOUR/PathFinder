/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:22:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/08 00:24:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pathfinder.h"

char	*pf_strdup(char const *s)
{
	char	*output;
	char	*p;

	if (!s)
		return (NULL);
	output = malloc((pf_strlen(s) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	p = output;
	while (*s)
		*p++ = *s++;
	*p = 0;
	return (output);
}
