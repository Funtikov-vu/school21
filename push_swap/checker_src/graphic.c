/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:47:14 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/14 17:58:43 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	draw_rect(t_dblpoint start, t_dblpoint end, t_3point color, t_mlx mlx)
{
	int i;
	int j;

	i = start.x;
	j = start.y;
	while (i < end.x)
	{
		j = start.y;
		while (j < end.y)
		{
			if (i < WD_X && j < WD_Y)
			{
				mlx.img_data[i * 4 + 4 * WD_X * j + 2] = color.x;
				mlx.img_data[i * 4 + 4 * WD_X * j + 1] = color.y;
				mlx.img_data[i * 4 + 4 * WD_X * j] = color.z;
			}
			j++;
		}
		i++;
	}
}

void	draw_a(t_arrnum *a, t_all all, int isblack)
{
	int			i;
	t_dblpoint	start;
	t_dblpoint	end;
	t_3point	pntcolor;

	i = 0;
	while (i < a->size)
	{
		ft_dblpointset(&start, 0, WD_Y - all.height * (i + 1));
		ft_dblpointset(&end, all.wide * ft_abs(a->arr[i]),
				WD_Y - all.height * i);
		if (!isblack)
		{
			if (a->arr[i] > 0)
				ft_3pntset(&pntcolor, 32, 178, 170);
			else
				ft_3pntset(&pntcolor, 95, 158, 160);
		}
		else
		{
			ft_3pntset(&pntcolor, 0, 0, 0);
		}
		draw_rect(start, end, pntcolor, all.mlx);
		i++;
	}
}

void	draw_b(t_arrnum *a, t_all all, int isblack)
{
	int			i;
	t_dblpoint	start;
	t_dblpoint	end;
	t_3point	pntcolor;

	i = 0;
	while (i < a->size)
	{
		ft_dblpointset(&start, WD_X / 2, WD_Y - all.height * (i + 1));
		ft_dblpointset(&end, WD_X / 2 + all.wide *
				ft_abs(a->arr[i]), WD_Y - all.height * i);
		if (!isblack)
		{
			if (a->arr[i] > 0)
				ft_3pntset(&pntcolor, 32, 178, 170);
			else
				ft_3pntset(&pntcolor, 95, 158, 160);
		}
		else
			ft_3pntset(&pntcolor, 0, 0, 0);
		draw_rect(start, end, pntcolor, all.mlx);
		i++;
	}
}

int		deal_key(int key, t_all *all)
{
	char	*s;
	void	(*f)();

	if (key == 53)
		exit(1);
	else if (key == 49)
	{
		draw_a(all->a, *all, 1);
		draw_b(all->b, *all, 1);
		if (get_next_line(0, &s))
		{
			f = get_f(s);
			ft_strdel(&s);
			f(all->a, all->b);
			draw_a(all->a, *all, 0);
			draw_b(all->b, *all, 0);
			mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr,
					all->mlx.img_ptr, 0, 0);
		}
		else
			ft_strdel(&s);
	}
	return (0);
}

void	visual_checker(t_arrnum *a, t_arrnum *b)
{
	t_mlx	mlx;
	t_all	all;

	init(&mlx);
	all.mlx = mlx;
	all.a = a;
	all.b = b;
	all.wide = ((1.0 * WD_X - 10) / 2) /
		(ft_max(a->arr[ft_arrposmax(a->arr, a->size)],
				ft_abs(a->arr[ft_arrposmin(a->arr, a->size)])));
	all.height = (1.0 * WD_Y) / a->size;
	draw_a(a, all, 0);
	draw_b(b, all, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, deal_key, &all);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, ft_end, NULL);
	mlx_loop(mlx.mlx_ptr);
}
