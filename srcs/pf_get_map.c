/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:57:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/14 18:16:01 by jodufour         ###   ########.fr       */
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

static int	pf_parse_file(int fd, char **output, char *buff)
{
	char	*dent;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == READ_ERROR)
			return (READ_ERROR);
		buff[ret] = 0;
		dent = *output;
		*output = pf_strjoin(*output, buff);
		free(dent);
		if (!(*output))
			return (STRJOIN_ERR_CODE);
	}
	return (SUCCESS);
}

char	*pf_get_map(char const *file)
{
	char	*output;
	char	*buff;
	int		fd;
	int		ret;

	output = NULL;
	buff = malloc((BUFF_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == OPEN_ERROR)
		return (pf_free_and_quit(buff, output));
	ret = pf_parse_file(fd, &output, buff);
	if (ret != SUCCESS)
		return (pf_free_and_quit(buff, output));
	close(fd);
	return (output);
}
