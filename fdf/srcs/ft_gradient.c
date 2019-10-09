/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gradient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:51:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/01/20 16:59:01 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdflib.h"

int			ft_gradient(int x, int delta, int color_min, int color_max)
{
	int			result;
	long double	delta_fract;
	long double	x_fract;

	delta_fract = delta;
	x_fract = x;
	if (!delta)
		return (color_max);
	result = 0;
	result += (color_min >> 16) +
		(long double)((color_max >> 16) - (color_min >> 16)) /
		delta_fract * x_fract;
	result *= 256;
	result += (color_min >> 8) % 256 +
		(long double)((color_max >> 8) % 256 - (color_min >> 8) % 256) /
		delta_fract * x_fract;
	result *= 256;
	result += color_min % 256 +
		(long double)(color_max % 256 - color_min % 256) /
		delta_fract * x_fract;
	return (result);
}
