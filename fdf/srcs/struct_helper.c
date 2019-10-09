/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:34:51 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/17 18:04:26 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdflib.h"

void		set_pntarr(t_pntarr *pntarr, t_3point **pnt,
		int size_x, int size_y)
{
	pntarr->pnt = pnt;
	pntarr->size_x = size_x;
	pntarr->size_y = size_y;
}

void		set_mlx(t_mlx *mlx, void *mlx_ptr, void *win_ptr)
{
	mlx->mlx_ptr = mlx_ptr;
	mlx->win_ptr = win_ptr;
}

void		set_all(t_all *all, t_mlx mlx, t_pntarr pntarr)
{
	all->pntarr = pntarr;
	all->temp = cpy_pntarr(all->pntarr);
	all->mlx = mlx;
	ft_3pntset(&all->shift, 0, 0, 0);
	ft_3pntset(&all->ang, 0, 0, 0);
	all->scale = 1;
}

t_pntarr	*cpy_pntarr(t_pntarr pntarr)
{
	t_pntarr	*res;
	int			i;

	i = 0;
	res = (t_pntarr*)malloc(sizeof(t_pntarr));
	res->pnt = (t_3point **)malloc(sizeof(t_3point *) * pntarr.size_y);
	while (i < pntarr.size_y)
	{
		res->pnt[i] = (t_3point*)malloc(pntarr.size_x * sizeof(t_3point));
		ft_memcpy(res->pnt[i], pntarr.pnt[i], pntarr.size_x * sizeof(t_3point));
		i++;
	}
	res->size_x = pntarr.size_x;
	res->size_y = pntarr.size_y;
	return (res);
}

void		del_pntarr(t_pntarr *pntarr)
{
	int		i;

	i = 0;
	while (i < pntarr->size_y)
	{
		free(pntarr->pnt[i]);
		i++;
	}
	free(pntarr->pnt);
	free(pntarr);
}
