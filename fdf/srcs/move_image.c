/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:26:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/01/17 18:28:42 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdflib.h"

void		move_to_zero(t_pntarr pntarr)
{
	t_3point	spnt;

	ft_3pntset(&spnt,
		-pntarr.pnt[(pntarr.size_y - 1) / 2][(pntarr.size_x - 1) / 2].x,
		-pntarr.pnt[(pntarr.size_y - 1) / 2][(pntarr.size_x - 1) / 2].y,
		0);
	shift(pntarr, spnt);
}

void		move_back(t_pntarr pntarr)
{
	t_3point	spnt;

	ft_3pntset(&spnt,
		1280 - pntarr.pnt[(pntarr.size_y - 1) / 2][(pntarr.size_x - 1) / 2].x,
		720 - pntarr.pnt[(pntarr.size_y - 1) / 2][(pntarr.size_x - 1) / 2].y,
		0);
	shift(pntarr, spnt);
}
