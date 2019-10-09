/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:34:08 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 15:52:31 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_end(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	init(t_mlx *mlx)
{
	mlx->bpp = 32;
	mlx->size_line = 4 * WD_X;
	mlx->endian = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WD_X, WD_Y, "PS");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WD_X, WD_Y);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
}

void	ft_dblpointset(t_dblpoint *p, double x, double y)
{
	p->x = x;
	p->y = y;
}
