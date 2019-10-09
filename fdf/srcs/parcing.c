/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:48:45 by udraugr-          #+#    #+#             */
/*   Updated: 2019/01/29 15:21:16 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdflib.h"

static t_3point		*read_pnts(char *line, int cnt, int line_nb)
{
	t_3point	*res;
	int			i;
	char		**temp;
	char		*col;

	res = (t_3point*)malloc(cnt * sizeof(t_3point));
	temp = ft_strsplit(line, ' ');
	i = 0;
	while (i < cnt)
	{
		ft_3pntset(&(res[i]), i, line_nb, ft_atoi(temp[i]));
		if ((col = ft_strchr(temp[i], ',')))
			res[i].color = ft_atoi_base(col + 3, 16);
		else
			res[i].color = -1;
		i++;
	}
	ft_arrstrdel(temp);
	return (res);
}

static void			ft_altitude(t_3point **pnt, int max_x, int max_y)
{
	int		i;
	int		j;
	int		max_z;
	int		min_z;

	i = -1;
	max_z = pnt[0][0].z;
	min_z = pnt[0][0].z;
	while (++i < max_y)
	{
		j = -1;
		while (++j < max_x)
		{
			max_z = (pnt[i][j].z > max_z) ? pnt[i][j].z : max_z;
			min_z = (pnt[i][j].z < min_z) ? pnt[i][j].z : min_z;
		}
	}
	while (--i > -1)
	{
		j = max_x;
		while (--j > -1)
			pnt[i][j].color = (pnt[i][j].color < 0) ? ft_gradient(
			max_z - pnt[i][j].z, ft_abs(max_z - min_z),
			0x905010, 0x309060) : pnt[i][j].color;
	}
}

void				ft_parcing(int argc, char **argv, t_pntarr *pntarr)
{
	char		*line;
	int			fd;
	int			temp;

	if (argc != 2)
		ft_usage(argv[0]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	set_pntarr(pntarr, 0, 0, 0);
	while (get_next_line(fd, &line))
	{
		pntarr->pnt = (t_3point **)ft_memrealloc(pntarr->pnt,
				sizeof(t_3point *) * (pntarr->size_y),
				sizeof(t_3point *) * (pntarr->size_y + 1));
		pntarr->size_x = ft_strwrdcnt(line, ' ');
		if (pntarr->size_y != 0 && pntarr->size_x != temp)
			ft_error();
		pntarr->pnt[pntarr->size_y] = read_pnts(line,
				pntarr->size_x, pntarr->size_y);
		temp = pntarr->size_x;
		pntarr->size_y++;
		free(line);
	}
	pntarr->size_x == 0 ? ft_error() : 0 == 1;
	ft_altitude(pntarr->pnt, pntarr->size_x, pntarr->size_y);
}
