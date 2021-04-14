/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:57:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/13 12:47:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pathfinder.h"

static void	*pf_free_and_quit(char *buff, char *output)
{
	free(buff);
	free(output);
	return (NULL);
}

char		*pf_get_map(char *file)
{
	char	*output;
	char	*buff;
	char	*dent;
	int		fd;
	int		ret;

	output = NULL;
	buff = malloc((BUFF_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == OPEN_ERROR)
		return (pf_free_and_quit(buff, output));
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == READ_ERROR)
			return (pf_free_and_quit(buff, output));
		buff[ret] = 0;
		dent = output;
		output = pf_strjoin(output, buff);
		free(dent);
	}
	close(fd);
	return (output);
}
