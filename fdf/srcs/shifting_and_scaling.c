/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifting_and_scaling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:30:03 by udraugr-          #+#    #+#             */
/*   Updated: 2019/01/29 15:42:21 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdflib.h"

void		shift_z(t_pntarr pntarr, int shift)
{
	int	i;
	int	j;

	i = 0;
	while (i < pntarr.size_y)
	{
		j = 0;
		while (j < pntarr.size_x)
		{
			if (pntarr.pnt[i][j].z)
				pntarr.pnt[i][j].z += shift;
			j++;
		}
		i++;
	}
}

void		scaling(t_pntarr pntarr, int k)
{
	int i;
	int j;

	i = 0;
	while (i < pntarr.size_y)
	{
		j = 0;
		while (j < pntarr.size_x)
		{
			pntarr.pnt[i][j].x *= k;
			pntarr.pnt[i][j].y *= k;
			pntarr.pnt[i][j].z *= k;
			j++;
		}
		i++;
	}
}

void		shift(t_pntarr pntarr, t_3point pnt)
{
	int i;
	int j;

	i = 0;
	while (i < pntarr.size_y)
	{
		j = 0;
		while (j < pntarr.size_x)
		{
			pntarr.pnt[i][j].x += pnt.x;
			pntarr.pnt[i][j].y += pnt.y;
			pntarr.pnt[i][j].z += pnt.z;
			j++;
		}
		i++;
	}
}
