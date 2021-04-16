/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:35:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/04/17 01:16:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pathfinder.h"

static uint32_t	pf_min2(int *matrix, uint32_t idx1, uint32_t idx2)
{
	if (!matrix[idx1] || matrix[idx1] == -1)
		return (idx2);
	if (!matrix[idx2] || matrix[idx2] == -1)
		return (idx1);
	if (matrix[idx1] < matrix[idx2])
		return (idx1);
	return (idx2);
}

static uint32_t	pf_min3(int *matrix, uint32_t idx1, uint32_t idx2,
	uint32_t idx3)
{
	if (!matrix[idx1] || matrix[idx1] == -1)
		return (pf_min2(matrix, idx2, idx3));
	if (!matrix[idx2] || matrix[idx2] == -1)
		return (pf_min2(matrix, idx1, idx3));
	if (!matrix[idx3] || matrix[idx3] == -1)
		return (pf_min2(matrix, idx1, idx2));
	if (matrix[idx1] <= matrix[idx2]
		&& matrix[idx1] <= matrix[idx2])
		return (idx1);
	else if (matrix[idx2] <= matrix[idx1]
		&& matrix[idx2] <= matrix[idx3])
		return (idx2);
	return (idx3);
}

static uint32_t	pf_min4(int *matrix, uint32_t idx1, uint32_t idx2,
	uint32_t idx3, uint32_t idx4)
{
	return (pf_min2(matrix, pf_min2(matrix, idx1, idx2), pf_min2(matrix, idx3, idx4)));
}

static uint32_t	pf_get_prev_low_idx(int *matrix, uint32_t dim[2], uint32_t idx)
{
	if (!(idx / dim[W]) && !(idx % dim[W]))										/* BR */
		return (pf_min2(matrix, idx + dim[W], idx + 1));
	else if (!(idx / dim[W]) && (idx % dim[W]) == (dim[W] - 1))					/* LB */
		return (pf_min2(matrix, idx - 1, idx + dim[W]));
	else if ((idx / dim[W]) == (dim[H] - 1) && !(idx % dim[W]))					/* RT */
		return (pf_min2(matrix, idx + 1, idx - dim[W]));
	else if ((idx / dim[W]) == (dim[H] - 1) && (idx % dim[W]) == (dim[W] - 1))	/* TL */
		return (pf_min2(matrix, idx - dim[W], idx - 1));
	else if (!(idx / dim[W]))													/* LBR */
		return (pf_min3(matrix, idx - 1, idx + dim[W], idx + 1));
	else if ((idx / dim[W]) == (dim[H] - 1))									/* RTL */
		return (pf_min3(matrix, idx + 1, idx - dim[W], idx + 1));
	else if (!(idx % dim[W]))													/* BRT */
		return (pf_min3(matrix, idx + dim[W], idx + 1, idx - dim[W]));
	else if ((idx % dim[W]) == (dim[W] - 1))									/* TLB */
		return (pf_min3(matrix, idx - dim[W], idx - 1, idx + dim[W]));
	else																		/* TLBR */
		return (pf_min4(matrix, idx - dim[W], idx - 1, idx + dim[W], idx + 1));
}

t_cell_lst	*pf_get_path(int *matrix, uint32_t dim[2], uint32_t idx[3])
{
	t_cell_lst	*path;

	path = pf_lst_new(idx[I_LOW]);
	while (idx[I_LOW] != idx[I_START])
	{
		printw("idx[I_LOW] == %u\n", idx[I_LOW]);
		pf_pause();
		idx[I_LOW] = pf_get_prev_low_idx(matrix, dim, idx[I_LOW]);
		path = pf_lst_add_back(path, idx[I_LOW]);
		if (!path)
			return (NULL);
	}
	return (path);
}
