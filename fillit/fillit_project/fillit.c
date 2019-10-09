/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:52:59 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/08 13:29:55 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillib.h"

static int	ft_is_ok(int arr[8], char greed[20][20], int *min_sqrt, int coor[2])
{
	int		j;
	int		x;
	int		y;

	j = 0;
	x = coor[0];
	y = coor[1];
	while (j <= 6)
	{
		if (x + arr[j + 1] > *min_sqrt - 1 || x + arr[j + 1] < 0
				|| y + arr[j] > *min_sqrt - 1 || y + arr[j] < 0
				|| (greed[y + arr[j]][x + arr[j + 1]] != '.'))
			return (0);
		j += 2;
	}
	return (1);
}

static void	ft_write(int arr[8], int coor[2], char c, char greed[20][20])
{
	int		j;
	int		x;
	int		y;

	x = coor[0];
	y = coor[1];
	j = 0;
	while (j <= 6)
	{
		greed[y + arr[j]][x + arr[j + 1]] = c;
		j += 2;
	}
}

static int	ft_increase_sqr(int count, int *min_sqrt, int arr[26][8],
		char greed[20][20])
{
	if (count != 0)
		return (-1);
	else
	{
		(*min_sqrt)++;
		ft_fill_dot(greed);
		return (ft_fill(min_sqrt, arr, greed, 0));
	}
}

int			ft_fill(int *min_sqrt, int arr[26][8], char greed[20][20],
		int count)
{
	int		x;
	int		y;
	int		coor[2];

	x = 0;
	y = 0;
	if (count > 26 || arr[count][0] == -1)
		return (1);
	while (x * y <= (*min_sqrt - 1) * (*min_sqrt - 1))
	{
		coor[0] = x;
		coor[1] = y;
		if (ft_is_ok(arr[count], greed, min_sqrt, coor))
		{
			ft_write(arr[count], coor, 'A' + count, greed);
			if (ft_fill(min_sqrt, arr, greed, count + 1) == 1)
				return (1);
			ft_write(arr[count], coor, '.', greed);
		}
		if (++x == *min_sqrt)
			ft_increase_y(&x, &y);
		if (y == *min_sqrt)
			return (ft_increase_sqr(count, min_sqrt, arr, greed));
	}
	return (-1);
}

void		fillit(int arr[26][8], int quantity)
{
	int		min_sqrt;
	int		i;
	int		j;
	char	greed[20][20];

	ft_fill_dot(greed);
	min_sqrt = ft_sqrt(quantity * 4);
	ft_fill(&min_sqrt, arr, greed, 0);
	i = 0;
	j = 0;
	while (j < min_sqrt)
	{
		write(1, &(greed[j][i]), 1);
		i++;
		if (i == min_sqrt)
		{
			write(1, "\n", 1);
			if (j == min_sqrt - 1)
				break ;
			j++;
			i = 0;
		}
	}
}
