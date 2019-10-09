/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:14:23 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/29 15:52:38 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdflib.h"

static void	take_key_angle_and_scale(t_all *all, int key)
{
	if (key == 89)
		all->ang.y += 1;
	else if (key == 86)
		all->ang.x += 1;
	else if (key == 83)
		all->ang.z += 1;
	else if (key == 91)
		all->ang.y -= 1;
	else if (key == 87)
		all->ang.x -= 1;
	else if (key == 84)
		all->ang.z -= 1;
	else if (key == 123)
		all->shift.x -= MOVE;
	else if (key == 124)
		all->shift.x += MOVE;
	else if (key == 125)
		all->shift.y += MOVE;
	else if (key == 126)
		all->shift.y -= MOVE;
	else if (key == 78)
		all->scale -= DEF_SCALE;
	else if (key == 69)
		all->scale += DEF_SCALE;
}

int			deal_key(int key, t_all *all)
{
	static long double		z_move = 0;

	if (key == 53)
		exit(1);
	else if (key == 92)
		z_move += 5;
	else if (key == 88)
		z_move -= 5;
	take_key_angle_and_scale(all, key);
	all->mlx.img_data = draw_pnt(*(all->temp), all->mlx, 0);
	del_pntarr(all->temp);
	all->temp = cpy_pntarr(all->pntarr);
	shift_z(*(all->temp), z_move);
	move_to_zero(*(all->temp));
	scaling(*(all->temp), all->scale);
	x_rotate(*(all->temp), all->ang.x * RANGLE);
	y_rotate(*(all->temp), all->ang.y * RANGLE);
	z_rotate(*(all->temp), all->ang.z * RANGLE);
	move_back(*(all->temp));
	shift(*(all->temp), all->shift);
	all->mlx.img_data = draw_pnt(*(all->temp), all->mlx, 1);
	mlx_put_image_to_window(all->mlx.mlx_ptr,
			all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
	return (0);
}

void		iso(t_pntarr pntarr)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < pntarr.size_y)
	{
		j = 0;
		while (j < pntarr.size_x)
		{
			temp = pntarr.pnt[i][j].x;
			pntarr.pnt[i][j].x = (temp - pntarr.pnt[i][j].y)
				* cos(PI / 6);
			pntarr.pnt[i][j].y = -pntarr.pnt[i][j].z +
				(temp + pntarr.pnt[i][j].y) * sin(PI / 6);
			j++;
		}
		i++;
	}
}

void		init(t_mlx *mlx, int argc, char **argv, t_pntarr *pntarr)
{
	mlx->bpp = 32;
	mlx->size_line = 4 * 2560;
	mlx->endian = 0;
	ft_parcing(argc, argv, pntarr);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 2560, 1440, "FDF");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 2560, 1440);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
}

int			main(int argc, char **argv)
{
	t_mlx		mlx;
	t_pntarr	pntarr;
	t_all		all;
	t_3point	spnt;
	int			kf;

	init(&mlx, argc, argv, &pntarr);
	kf = 24 / (sqrt((pntarr.size_y * 625 * pntarr.size_y + 625 *
					pntarr.size_x * pntarr.size_x)) / 2500 + 1) + 1;
	scaling(pntarr, kf);
	ft_3pntset(&spnt,
			1280 - pntarr.pnt[pntarr.size_y - 1][pntarr.size_x - 1].x / 2,
			720 - pntarr.pnt[pntarr.size_y - 1][pntarr.size_x - 1].y / 2, 0);
	shift(pntarr, spnt);
	set_all(&all, mlx, pntarr);
	mlx.img_data = draw_pnt(pntarr, mlx, 1);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, deal_key, &all);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, ft_end, NULL);
	mlx_loop(mlx.mlx_ptr);
}
