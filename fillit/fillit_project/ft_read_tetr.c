/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readTetr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:30:05 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/08 13:48:58 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillib.h"
#include "../libft/libft.h"

int		ft_is_cnt(int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
	{
		if (y1 - y2 == 1 || y1 - y2 == -1)
			return (1);
	}
	else if (y1 == y2)
	{
		if (x1 - x2 == 1 || x1 - x2 == -1)
			return (1);
	}
	return (0);
}

int		ft_check_connect(int ar[8])
{
	if (ft_is_cnt(ar[0], ar[1], ar[2], ar[3]) +
			ft_is_cnt(ar[0], ar[1], ar[4], ar[5]) +
			ft_is_cnt(ar[0], ar[1], ar[6], ar[7]) +
			ft_is_cnt(ar[2], ar[3], ar[0], ar[1]) +
			ft_is_cnt(ar[2], ar[3], ar[4], ar[5]) +
			ft_is_cnt(ar[2], ar[3], ar[6], ar[7]) +
			ft_is_cnt(ar[4], ar[5], ar[2], ar[3]) +
			ft_is_cnt(ar[4], ar[5], ar[0], ar[1]) +
			ft_is_cnt(ar[4], ar[5], ar[6], ar[7]) +
			ft_is_cnt(ar[6], ar[7], ar[2], ar[3]) +
			ft_is_cnt(ar[6], ar[7], ar[4], ar[5]) +
			ft_is_cnt(ar[6], ar[7], ar[0], ar[1]) < 5)
		return (0);
	return (1);
}

void	ft_figstandart(int ar[26][8], int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		while (ar[i][0] && ar[i][2] && ar[i][4] && ar[i][6])
		{
			ar[i][0]--;
			ar[i][2]--;
			ar[i][4]--;
			ar[i][6]--;
		}
		while (ar[i][1] && ar[i][3] && ar[i][5] && ar[i][7])
		{
			ar[i][1]--;
			ar[i][3]--;
			ar[i][5]--;
			ar[i][7]--;
		}
		i++;
	}
}

int		ft_fillar(char buf[22], int tetrims[26][8], int nb)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		if (i % 5 == 4 || i == 20)
		{
			if (buf[i++] != '\n')
				return (0);
		}
		else if (buf[i] == '#')
		{
			if (j > 3)
				return (0);
			tetrims[nb][2 * j + 1] = i % 5;
			tetrims[nb][2 * j++] = i++ / 5;
		}
		else if (buf[i++] != '.')
			return (0);
	}
	if (j != 4 || !ft_check_connect(tetrims[nb]))
		return (0);
	return (1);
}

int		ft_read_tetr(int tetrims[26][8], int fd)
{
	char		buf[22];
	int			i;
	int			ret;
	int			flag;

	i = 0;
	while ((ret = read(fd, buf, 21)) && i < 26)
	{
		if (ret < 0)
			return (0);
		buf[ret] = '\0';
		if (!ft_fillar(buf, tetrims, i))
			return (0);
		i++;
		flag = ret;
	}
	if (!i || i > 26 || flag != 20)
		return (0);
	ft_figstandart(tetrims, i);
	if (i != 26)
		tetrims[i][0] = -1;
	return (i);
}
