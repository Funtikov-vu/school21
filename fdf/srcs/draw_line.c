/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:27:43 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/20 17:29:04 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdflib.h"

static void		ft_fill_img_data(t_mlx mlx, t_3point p0, int color)
{
	mlx.img_data[p0.x * 4 + 4 * 2560 * p0.y + 2] = color / (256 * 256);
	mlx.img_data[p0.x * 4 + 4 * 2560 * p0.y + 1] = (color / 256) % 256;
	mlx.img_data[p0.x * 4 + 4 * 2560 * p0.y] = color % 256;
}

static char		*plot_lline(t_3point p0, t_3point p1, t_mlx mlx, int color)
{
	t_point		delta_pnt;
	int			coff;
	int			delta;

	ft_pntset(&delta_pnt, p1.x - p0.x, p1.y - p0.y);
	coff = (delta_pnt.y >= 0) ? 1 : -1;
	delta_pnt.y = (delta_pnt.y >= 0) ? delta_pnt.y : -delta_pnt.y;
	delta = 2 * delta_pnt.y - delta_pnt.x;
	while (p0.x <= p1.x)
	{
		if (p0.y >= 0 && p0.y < 1440 && p0.x >= 0 && p0.x < 2560)
			ft_fill_img_data(mlx, p0, ft_gradient(p0.x - p1.x + delta_pnt.x,
					delta_pnt.x, p0.color, p1.color) * color);
		if (delta > 0)
		{
			p0.y += coff;
			delta = delta - 2 * delta_pnt.x;
		}
		delta = delta + 2 * delta_pnt.y;
		p0.x++;
	}
	return (mlx.img_data);
}

static char		*plot_hline(t_3point p0, t_3point p1, t_mlx mlx, int color)
{
	t_point		delta_pnt;
	int			coff;
	int			delta;

	ft_pntset(&delta_pnt, p1.x - p0.x, p1.y - p0.y);
	coff = (delta_pnt.x >= 0) ? 1 : -1;
	delta_pnt.x = (delta_pnt.x >= 0) ? delta_pnt.x : -delta_pnt.x;
	delta = 2 * delta_pnt.x - delta_pnt.y;
	while (p0.y <= p1.y)
	{
		if (p0.y >= 0 && p0.y < 1440 && p0.x >= 0 && p0.x < 2560)
			ft_fill_img_data(mlx, p0, ft_gradient(p0.y - p1.y + delta_pnt.y,
					delta_pnt.y, p0.color, p1.color) * color);
		if (delta > 0)
		{
			p0.x += coff;
			delta = delta - 2 * delta_pnt.y;
		}
		delta = delta + 2 * delta_pnt.x;
		p0.y++;
	}
	return (mlx.img_data);
}

static char		*plot_line(t_3point p0, t_3point p1, t_mlx mlx, int color)
{
	if ((p0.x < 0 && p1.x < 0) || (p0.x > 2559 && p1.x > 2559) ||
			(p0.y < 0 && p1.y < 0) || (p0.y > 1439 && p1.y > 1439))
		return (mlx.img_data);
	else if (ft_abs(p1.y - p0.y) < ft_abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			return (plot_lline(p1, p0, mlx, color));
		else
			return (plot_lline(p0, p1, mlx, color));
	}
	else
	{
		if (p0.y > p1.y)
			return (plot_hline(p1, p0, mlx, color));
		else
			return (plot_hline(p0, p1, mlx, color));
	}
}

char			*draw_pnt(t_pntarr pntarr, t_mlx mlx, int color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < pntarr.size_y)
	{
		j = -1;
		while (++j < pntarr.size_x)
		{
			if (i + 1 < pntarr.size_y)
				mlx.img_data = plot_line(pntarr.pnt[i][j],
						pntarr.pnt[i + 1][j], mlx, color);
			if (j + 1 < pntarr.size_x)
				mlx.img_data = plot_line(pntarr.pnt[i][j],
						pntarr.pnt[i][j + 1], mlx, color);
		}
	}
	return (mlx.img_data);
}
