/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:51:49 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/17 15:42:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdflib.h"

void	x_rotate(t_pntarr pntarr, double alpha)
{
	int i;
	int j;
	int	old_y;
	int	old_z;

	i = 0;
	while (i < pntarr.size_y)
	{
		j = 0;
		while (j < pntarr.size_x)
		{
			old_y = pntarr.pnt[i][j].y;
			old_z = pntarr.pnt[i][j].z;
			pntarr.pnt[i][j].y = old_y * cos(alpha) + old_z * sin(alpha);
			pntarr.pnt[i][j].z = -old_y * sin(alpha) + old_z * cos(alpha);
			j++;
		}
		i++;
	}
}

void	y_rotate(t_pntarr pntarr, double alpha)
{
	int i;
	int j;
	int old_x;
	int	old_z;

	i = 0;
	while (i < pntarr.size_y)
	{
		j = 0;
		while (j < pntarr.size_x)
		{
			old_x = pntarr.pnt[i][j].x;
			old_z = pntarr.pnt[i][j].z;
			pntarr.pnt[i][j].x = old_x * cos(alpha) + old_z * sin(alpha);
			pntarr.pnt[i][j].z = -old_x * sin(alpha) + old_z * cos(alpha);
			j++;
		}
		i++;
	}
}

void	z_rotate(t_pntarr pntarr, double alpha)
{
	int i;
	int j;
	int old_x;
	int	old_y;

	i = 0;
	while (i < pntarr.size_y)
	{
		j = 0;
		while (j < pntarr.size_x)
		{
			old_x = pntarr.pnt[i][j].x;
			old_y = pntarr.pnt[i][j].y;
			pntarr.pnt[i][j].x = old_x * cos(alpha) - old_y * sin(alpha);
			pntarr.pnt[i][j].y = old_x * sin(alpha) + old_y * cos(alpha);
			j++;
		}
		i++;
	}
}
